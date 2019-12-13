/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:48:55 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 17:07:32 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int					ft_i(int i)
{
	static int		posix;

	if (i > -10)
		posix = i;
	return (posix);
}

t_select			*save_lstselect(t_select **lst)
{
	static t_select	**save;

	if (!save && lst && *lst)
		save = lst;
	return (*save);
}
