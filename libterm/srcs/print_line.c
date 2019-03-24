#include "libterm.h"

int	print_line(void)
{
	write(STDIN, "\r", 1);
	return (execute_str(PRINT_LINE));
}
