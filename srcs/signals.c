#include "ft_select.h"
#include <signal.h>

/*
** Handler function for terminating (ie dangerous) signals
*/

static void	sig_handler(int signo)
{
	reset_terminal_settings();
	signal(signo, SIG_DFL);
	raise(signo);
}

static void	sigint_handler(int signo)
{
	(void)signo;
	print_line();
}

static void	sigwinch_handler(int signo)
{

	print_list(lst_addr(NULL));
	(void)signo;
}

/*
** Setting up signal functions.
** KILL and STOP are not handled, and WILL leave you with a messy terminal
** Terminating (ie dangerous) signals reset the terminal, and then
** handles the signal with SIG_DFL.
** All non-terminating signals are left untouched, execpt WINCH
** INT signal does NOT exit the program.
*/

void		signal_setup(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGWINCH, sigwinch_handler);
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
	signal(SIGTSTP, sig_handler);
	signal(SIGTTIN, sig_handler);
	signal(SIGTTOU, sig_handler);
	signal(SIGXCPU, sig_handler);
	signal(SIGXFSZ, sig_handler);
	signal(SIGVTALRM, sig_handler);
	signal(SIGPROF, sig_handler);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
}
