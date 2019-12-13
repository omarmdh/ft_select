/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:43:13 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 17:44:20 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int				ft_fd_(int fd)
{
	static int			fdd;

	if (fd > -1)
		fdd = fd;
	return (fdd);
}

int						ft_putsfd(int p)
{
	write(ft_fd_(-5), &p, 1);
	return (1);
}

void					ft_print_selec(t_select *nd)
{
	if (!nd)
		return ;
	while (nd)
	{
		if (nd->color != NULL && ft_strcmp(nd->color, "\033[7m") == 0)
			ft_put2str(nd->name, " ");
		nd = nd->next;
	}
}

void					ft_print_fd(char *color, char *name, int fd)
{
	struct stat type;

	lstat(name, &type);
	if (S_ISLNK(type.st_mode))
	{
		ft_putstr_fd(color, fd);
		ft_put4str(tgetstr("us", NULL), "\033[1;35m", name, "\033[0m");
	}
	else if (S_ISDIR(type.st_mode))
	{
		ft_putstr_fd(color, fd);
		ft_put4str(tgetstr("us", NULL), "\033[1;36m", name, "\033[0m");
	}
	else if (!S_ISDIR(type.st_mode) && type.st_mode & S_IXOTH)
	{
		ft_putstr_fd(color, fd);
		ft_put4str(tgetstr("us", NULL), "\033[1;31m", name, "\033[0m");
	}
	else
	{
		ft_putstr_fd(color, fd);
		ft_put4str(tgetstr("us", NULL), "\033[1;33m", name, "\033[0m");
	}
}

void					ft_print_argss(t_select *nd, int ii, int fd)
{
	int					i_j_col[3];
	int					maxlent;
	struct winsize		w;

	ioctl(fd, TIOCGWINSZ, &w);
	i_j_col[0] = 0;
	i_j_col[1] = 0;
	i_j_col[2] = -1;
	maxlent = ft_max_lent(nd);
	if (((w.ws_col / (maxlent + 1)) * w.ws_row) < ft_list_lent(nd)
			&& ft_putstr_fd("The window is too small !!", ft_fd_(fd)))
		return ;
	while (nd)
	{
		if ((i_j_col[2]++) && (i_j_col[0] + maxlent) > w.ws_col)
		{
			i_j_col[0] = 0;
			i_j_col[1]++;
		}
		tputs(tgoto(tgetstr("cm", NULL), i_j_col[0], i_j_col[1]), 0, ft_putsfd);
		(i_j_col[2] == ii) ? ft_print_fd(nd->color, nd->name,
		fd) : ft_put4str(nd->color, nd->name, nd->zero, "");
		i_j_col[0] = (i_j_col[0] + maxlent + 1);
		nd = nd->next;
	}
}
