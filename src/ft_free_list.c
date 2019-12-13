/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:18:45 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/12 21:06:50 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void				ft_freelist(t_select **n)
{
	t_select		*nd;
	t_select		*tmp;

	if (!*n || !n || (*n)->name == NULL)
		return ;
	nd = *n;
	while (nd)
	{
		tmp = nd->next;
		ft_strdel(&nd->name);
		ft_memdel((void**)&nd);
		nd = tmp;
	}
}
