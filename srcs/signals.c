#include <signal.h>
#include <unistd.h>
#include "libterm.h"


static void	sig_handler(int signo)
{
	reset_terminal();
	signal(signo, SIG_DFL);
	raise(signo);
}

static void	sigint_handler(int signo)
{
	(void)signo;
	write(1, "\n", 1);
}

static void	sigwinch_handler(int signo)
{
	(void)signo;
	write(1, "Windows changed\n", ft_strlen("Windows changed\n"));
}

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
