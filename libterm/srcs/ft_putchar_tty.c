#include "libterm.h"

int		ft_putchar_tty(int c)
{
	if (write(g_dev_tty, &c, 1) == -1)
		return (0);
	else
		return (1);
}
