#include "ft_select.h"
#include <signal.h>

/*
** Handler function for terminating (aka dangerous) signals
*/

static void	sig_handler(int signo)
{
	t_arg_list *lst;

	lst = lst_addr(NULL);
	reset_terminal_settings();
	free_list(lst);
	exit (signo);
}

static void	sigcont_handler(int signo)
{
	t_print_info	*info;
	t_arg_list		*lst;

	info = info_addr(NULL);
	lst = lst_addr(NULL);
	if (setup_terminal_settings() == 0)
	{
		reset_terminal_settings();
		exit(1);
	}
	execute_str(INVISIBLE);
	execute_str(BEGIN_LINE);
	get_print_info(lst, info);
	print_list(lst, info);
	signal_setup();
	(void)signo;
}

static void	sigwinch_handler(int signo)
{
	t_print_info	*info;
	t_arg_list		*lst;

	signal(SIGWINCH, SIG_DFL);
	info = info_addr(NULL);
	lst = lst_addr(NULL);
	get_print_info(lst, info);
	print_list(lst, info);
	(void)signo;
	signal(SIGWINCH, sigwinch_handler);
}

void		sigtstp_handler(int signo)
{
	(void)signo;
	reset_terminal_settings();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDOUT_FILENO, TIOCSTI, "\x1a");
}

/*
** Setting up signal functions.
** KILL and STOP are not handled, and WILL leave you with a messy terminal
** Terminating (aka dangerous) signals reset the terminal, and then exit.
** All non-terminating signals are left untouched, except WINCH and CONT
** INT signal does NOT exit the program.
*/

void		signal_setup(void)
{
	signal(SIGWINCH, sigwinch_handler);
	signal(SIGCONT, sigcont_handler);
	signal(SIGTSTP, sigtstp_handler);
	signal(SIGINT, sig_handler);
	signal(SIGHUP, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGILL, sig_handler);
	signal(SIGTRAP, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGEMT, sig_handler);
	signal(SIGFPE, sig_handler);
	signal(SIGBUS, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGSYS, sig_handler);
	signal(SIGPIPE, sig_handler);
	signal(SIGALRM, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGTTOU, sig_handler);
	signal(SIGTTIN, sig_handler);
	signal(SIGXCPU, sig_handler);
	signal(SIGXFSZ, sig_handler);
	signal(SIGVTALRM, sig_handler);
	signal(SIGPROF, sig_handler);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
}
