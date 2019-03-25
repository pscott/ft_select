#include "libterm.h"

int		err_no_str(char *cap)
{
	ft_putstr_fd("error: no str corresponding to \"", 2);
	ft_putstr_fd(cap ? cap : "(null)", 2);
	ft_putstr_fd("\" cap.", 2);
	print_line();
	return (0);
}
