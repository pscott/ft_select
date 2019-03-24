#include "libterm.h"

void	term_putstr_endline(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	print_line();
}

int		print_line(void)
{
	write(STDIN, "\r", 1);
	return (execute_str(PRINT_LINE));
}
