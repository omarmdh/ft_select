/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:18:08 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/13 11:59:57 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_sig_stp(int sig)
{
	sig = 1;
	tputs(tgetstr("te", NULL), 0, ft_putsfd);
	tputs(tgetstr("ve", NULL), 0, ft_putsfd);
	signal(SIGTSTP, SIG_DFL);
	ioctl(3, TIOCSTI, "\032");
}

void		ft_sig_cnt(int sig)
{
	sig = 1;
	ft_check_is_safe();
	tputs(tgetstr("vi", NULL), 0, ft_putsfd);
	ft_signal();
	sig_winch(1);
}

void		ft_signal2(void)
{
	signal(SIGWINCH, sig_winch);
	signal(SIGURG, ft_sig_catch);
	signal(SIGSTOP, ft_sig_catch);
	signal(SIGTSTP, ft_sig_stp);
	signal(SIGCONT, ft_sig_cnt);
	signal(SIGCHLD, ft_sig_catch);
	signal(SIGTTIN, ft_sig_catch);
	signal(SIGTTOU, ft_sig_catch);
	signal(23, ft_sig_catch);
	signal(SIGXCPU, ft_sig_catch);
	signal(SIGXFSZ, ft_sig_catch);
	signal(SIGVTALRM, ft_sig_catch);
	signal(SIGPROF, ft_sig_catch);
	signal(SIGINFO, ft_sig_catch);
	signal(SIGUSR1, ft_sig_catch);
	signal(SIGUSR2, ft_sig_catch);
}

void		ft_signal(void)
{
	signal(SIGHUP, ft_sig_catch);
	signal(SIGINT, ft_sig_catch);
	signal(SIGQUIT, ft_sig_catch);
	signal(SIGILL, ft_sig_catch);
	signal(SIGTRAP, ft_sig_catch);
	signal(SIGABRT, ft_sig_catch);
	signal(7, ft_sig_catch);
	signal(SIGFPE, ft_sig_catch);
	signal(SIGKILL, ft_sig_catch);
	signal(SIGBUS, ft_sig_catch);
	signal(SIGSEGV, ft_sig_catch);
	signal(SIGSYS, ft_sig_catch);
	signal(SIGPIPE, ft_sig_catch);
	signal(SIGALRM, ft_sig_catch);
	signal(SIGTERM, ft_sig_catch);
	ft_signal2();
}
