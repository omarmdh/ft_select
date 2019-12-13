/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_len_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:12:56 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/11 20:14:18 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

size_t			ft_max_lent(t_select *nd)
{
	size_t		lent;

	lent = 0;
	while (nd->next)
	{
		if (ft_strlen(nd->name) > lent)
			if (nd->name != NULL)
				lent = ft_strlen(nd->name);
		nd = nd->next;
	}
	return (lent);
}
