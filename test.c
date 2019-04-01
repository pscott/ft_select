#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>

void	setup_signals(void);

void	handler(int signo)
{
	char c;

	c = signo + '0';
	write(1, "signal handled", 16);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	cont_handler(int signo)
{
	char	buf[2];
	struct sigaction	sig_ign;
	struct sigaction	sig_dfl;

	sig_ign.sa_handler = SIG_IGN;
	sig_ign.sa_flags = SA_RESTART;

	sig_dfl.sa_handler = handler;
	sig_ign.sa_flags = SA_RESTART;

	sigaction(SIGTTOU, &sig_ign, NULL);
	if (tcsetpgrp(STDIN_FILENO, getpid()) == -1)
		exit(150);
	sigaction(SIGTTOU, &sig_dfl, NULL);
	buf[0] = -62;
	buf[1] = 0;
	ioctl(0, TIOCSTI, buf);
	write(1, "continuing\n", 11);
	(void)signo;
}

void	tstp_handler(int signo)
{
	(void)signo;
	write(1, "stopped\n", 8);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDOUT_FILENO, TIOCSTI, "\x1a");
}

void	setup_signals(void)
{
	struct sigaction	sig_usr;
	struct sigaction	sig_cont;
	struct sigaction	sig_ign;
	struct sigaction	sig_tstp;

	sig_usr.sa_handler = handler;
	sig_usr.sa_flags = SA_RESTART;

	sig_tstp.sa_handler = tstp_handler;
	sig_tstp.sa_flags = SA_RESTART;

	sig_ign.sa_handler = SIG_IGN;
	sig_ign.sa_flags = SA_RESTART;

	sig_cont.sa_handler = cont_handler;
	sig_cont.sa_flags = SA_RESTART;

	sigaction(SIGUSR1, &sig_usr, NULL);
	sigaction(SIGCONT, &sig_cont, NULL);
	signal(SIGTTOU, handler);
	signal(SIGTTIN, handler);
	sigaction(SIGTSTP, &sig_tstp, NULL);
}

int	main(void)
{
	char c;
	char ret;
	char  i;

	i = '\x41';
	ret = 0;
	setup_signals();
	while ((ret = read(STDIN_FILENO, &c, 1) > 0))
		;
	ret = ret + '0';
	write(1, "exited ", 7);
	write(1, &ret, 1);
	write(1, "\n", 7);
}
