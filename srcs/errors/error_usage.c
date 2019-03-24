#include "libterm.h"

int	err_usage(void)
{
	ft_putstr_fd("usage: ./ft_select [arg1] [arg2] [...] \n", STDERR);
	return (0);
}
