#include "libterm.h"

int		execute_str(char *cap)
{
	char	buf[50];
	char	*cap_str;
	char	*ap;

	ap = buf;
	if (cap && (cap_str = tgetstr(cap, &ap)))
	{
		tputs(buf, 1, ft_putchar); //tputs ?
		return (1);
	}
	else
		return (err_no_str(cap));
}
