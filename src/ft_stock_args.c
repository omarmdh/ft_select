/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:00:22 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 17:09:52 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int					ft_list_lent(t_select *nd)
{
	int				i;

	i = 0;
	while (nd)
	{
		nd = nd->next;
		i++;
	}
	return (i);
}

int					ft_del_node(t_select **n, int index)
{
	t_select		*prev;
	t_select		*tmp;

	if (!*n)
		return (1);
	tmp = *n;
	if (index == 0)
	{
		*n = tmp->next;
		ft_strdel(&tmp->name);
		ft_memdel((void**)&tmp);
		return (0);
	}
	while (index--)
	{
		if (tmp == NULL)
			return (1);
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	ft_strdel(&tmp->name);
	ft_memdel((void**)&tmp);
	return (0);
}

void				ft_new_node(t_select **nd)
{
	*nd = (t_select *)malloc(sizeof(t_select));
	(*nd)->color = NULL;
	(*nd)->zero = NULL;
	(*nd)->next = NULL;
	(*nd)->name = NULL;
}

t_select			*ft_stock_args(int ac, char **av)
{
	int				i;
	t_select		*nd;
	t_select		*head;

	i = ac - 1;
	head = NULL;
	while (i >= 0)
	{
		ft_new_node(&nd);
		nd->name = ft_strdup(av[i]);
		nd->index = i;
		nd->next = head;
		head = nd;
		i--;
	}
	return (head);
}
