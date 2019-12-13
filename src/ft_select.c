/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:06:13 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 21:08:03 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void				ft_sig_catch(int sig)
{
	t_select			*lst;

	sig = 0;
	lst = save_lstselect(NULL);
	tputs(tgetstr("ve", NULL), 0, ft_putsfd);
	tputs(tgetstr("te", NULL), 0, ft_putsfd);
	ft_freelist(&lst);
	exit(1);
}

void					sig_winch(int sig)
{
	t_select			*lst;

	lst = save_lstselect(NULL);
	sig = 1;
	tputs(tgetstr("cl", NULL), 0, ft_putsfd);
	ft_print_argss(lst, ft_i(-10), 2);
}

int						ft_check_is_safe(void)
{
	struct termios		config;
	char				*termname;
	int					fd;

	fd = open(ttyname(2), O_RDWR);
	if (tcgetattr(fd, &config) < 0)
		ft_putendl_fd("error", fd);
	config.c_lflag &= ~(ICANON);
	if (tcsetattr(fd, TCSANOW, &config) < 0)
		ft_putendl_fd("error", fd);
	termname = getenv("TERM");
	if (termname == NULL)
	{
		ft_putstr("ft_select: TERM Variable Not set !!");
		return (-1);
	}
	if (tgetent(NULL, termname) <= 0)
	{
		ft_putendl_fd("failure to unitialise Temrcap", 2);
		return (-1);
	}
	tputs(tgetstr("ti", NULL), 0, ft_putsfd);
	tputs(tgetstr("cl", NULL), 0, ft_putsfd);
	return (0);
}

int						ft_read_input(t_select **n, int *r)
{
	int					i;
	t_select			**nd;

	nd = n;
	i = 0;
	while (read(0, r, sizeof(int)) > 0)
	{
		ft_cursor_posix(*nd, *r, &i, ft_list_lent(*nd));
		ft_i(i);
		ft_search(*r, &i, *nd);
		if (ft_list_lent(*nd) == 1 && (*r == DEL || *r == DEL2))
			break ;
		if ((*r == DEL || *r == DEL2) && ft_del_node(nd, i) == 0)
			if (i == ft_list_lent(*nd) && i > 0)
				i--;
		if (*r == 32 && ft_select_rv(nd, i) == 0)
			(i < ft_list_lent(*nd) - 1) ? i++ : 0;
		if (*r == 27 || *r == 10)
			break ;
	//	ft_cursor_posix(*nd, *r, &i, ft_list_lent(*nd));
		*r = 0;
		tputs(tgetstr("cl", NULL), 0, ft_putsfd);
		ft_print_argss(*nd, i, 2);
	}
	return (*r);
}

int						main(int ac, char **av)
{
	t_select			*nd;
	int					r;
	struct termios		orig_termios;

	r = 0;
	if (ac > 1)
	{
		if (ft_check_is_safe() == -1)
			return (1);
		tcgetattr(2, &orig_termios);
		ft_signal();
		tputs(tgetstr("vi", NULL), 0, ft_putsfd);
		nd = ft_stock_args(ac - 1, &av[1]);
		save_lstselect(&nd);
		ft_print_argss(nd, 0, 2);
		r = ft_read_input(&nd, &r);
		tputs(tgetstr("ve", NULL), 0, ft_putsfd);
		tputs(tgetstr("te", NULL), 0, ft_putsfd);
		if (r == 10)
			ft_print_selec(nd);
		ft_freelist(&nd);
		tcsetattr(2, TCSANOW, &orig_termios);
	}
	else
		ft_putstr("Usage : ./ft_select <arg1> <arg2> ...\n");
}
