/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:57:40 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 17:08:09 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_search(int r, int *i, t_select *nd)
{
	int		index;

	index = 0;
	while (nd)
	{
		if (nd->name[0] == r)
		{
			*i = index;
			return ;
		}
		index++;
		nd = nd->next;
	}
}
