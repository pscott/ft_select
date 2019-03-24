#include <signal.h>
#include <unistd.h>
#include "libterm.h"


static void	sig_handler(int signo)
{
	reset_terminal();
	signal(SIGALRM, SIG_DFL);
	signal(SIGVTALRM, SIG_DFL);
	signal(SIGPROF, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGHUP, SIG_DFL);
	signal(SIGFPE, SIG_DFL);
	signal(SIGILL, SIG_DFL);
	signal(SIGSEGV, SIG_DFL);
	signal(SIGBUS, SIG_DFL);
	signal(SIGABRT, SIG_DFL);
	signal(SIGIOT, SIG_DFL);
	signal(SIGTRAP, SIG_DFL);
	signal(SIGEMT, SIG_DFL);
	signal(SIGSYS, SIG_DFL);
	raise(signo);
}

static void	sigint_handler(int signo)
{
	(void)signo;
	write(1, "\n", 1);
}

void		signal_setup(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGALRM, sig_handler);
	signal(SIGVTALRM, sig_handler);
	signal(SIGPROF, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGHUP, sig_handler);
	signal(SIGFPE, sig_handler);
	signal(SIGILL, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGBUS, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGIOT, sig_handler);
	signal(SIGTRAP, sig_handler);
	signal(SIGEMT, sig_handler);
	signal(SIGSYS, sig_handler);
}
