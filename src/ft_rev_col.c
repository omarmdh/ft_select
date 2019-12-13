/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:38:03 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 16:54:32 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				ft_select_rv(t_select **nd, int i)
{
	t_select		*n;
	int				index;

	index = 0;
	n = *nd;
	while (n)
	{
		if (index == i)
		{
			if (n->color == NULL)
			{
				n->color = "\033[7m";
				n->zero = "\033[m";
			}
			else
			{
				n->color = NULL;
				n->zero = NULL;
			}
		}
		n = n->next;
		index++;
	}
	return (0);
}
