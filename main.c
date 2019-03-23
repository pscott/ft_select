#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sig_handler(int signo)
{
	printf("Received signal num : %d\n", signo);
}

int	main(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\nCan't catch SIGINT\n");
	while (1)
		sleep(1);
	return (0);
}
