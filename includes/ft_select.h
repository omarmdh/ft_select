/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:38:45 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 17:33:51 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <sys/ioctl.h>
# include "../libft/libft.h"
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <stdio.h>

# define DEL2 2117294875
# define DEL 127
# define RIGHT 4414235
# define LEFT 4479771
# define UP 4283163
# define DOWN 4348699

typedef struct			s_select
{
	char				*color;
	char				*name;
	int					index;
	char				*zero;
	struct s_select		*next;
}						t_select;

t_select	*g_head;

int						ft_i(int i);
t_select				*save_lstselect(t_select **lst);
void					ft_search(int r, int *i, t_select *nd);
size_t					ft_max_lent(t_select *nd);
int						ft_check_is_safe(void);
void					sig_winch(int sig);
void					ft_cursor_posix(t_select *nd, int r, int *i, int ac);
int						ft_select_rv(t_select **nd, int i);
int						ft_list_lent(t_select *nd);
int						ft_putsfd(int p);
void					ft_print_selec(t_select *nd);
size_t					ft_max_lent(t_select *nd);
void					ft_print_argss(t_select *nd, int ii, int fd);
int						ft_del_node(t_select **n, int index);
void					ft_new_node(t_select **nd);
t_select				*ft_stock_args(int ac, char **av);
void					ft_freelist(t_select **n);
void					ft_new_node(t_select **nd);
t_select				*ft_stock_args(int ac, char **av);
void					ft_sig_catch(int sig);
void					ft_signal(void);
#endif
