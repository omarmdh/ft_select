/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_pisix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:34:30 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 17:16:33 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void					ft_cursor_posix(t_select *nd, int r, int *i, int ac)
{
	int					maxwordlen;
	int					termlen;
	struct winsize		w;

	ioctl(0, TIOCGWINSZ, &w);
	termlen = w.ws_col + 1;
	maxwordlen = ft_max_lent(nd) + 1;
	if (ac == 1)
	{
		*i = 0;
		return ;
	}
	if (r == RIGHT && *i == ac - 1)
		*i = -1;
	if (r == LEFT && *i == 0)
		*i = ac;
	if (r == LEFT && i > 0)
		(*i)--;
	if (r == RIGHT && *i <= ac)
		(*i)++;
	if (r == DOWN && *i + (termlen / maxwordlen) <= ac)
		*i = *i + (termlen / maxwordlen);
	if (r == UP && *i - (termlen / maxwordlen) >= 0)
		*i = *i - (termlen / maxwordlen);
}
