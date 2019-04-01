#include "libterm.h"

int		ft_putchar_err(int c)
{
	if (write(STDERR, &c, 1) == -1)
		return (0);
	return (1);
}

int		execute_str(char *cap)
{
	char	buf[50];
	char	*cap_str;
	char	*ap;

	ap = buf;
	if (cap && (cap_str = tgetstr(cap, &ap)))
	{
		tputs(buf, 1, ft_putchar_err); //tputs ?
		return (1);
	}
	else
		return (err_no_str(cap));
}
