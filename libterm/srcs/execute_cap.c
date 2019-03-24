#include "libterm.h"

int		execute_str(char *cap)
{
	char	buf[50];
	char	*cap_str;
	char	*ap;

	ap = buf;
	if (cap && (cap_str = tgetstr(cap, &ap)))
	{
		write(STDOUT, buf, ft_strlen(cap_str)); //tputs ?
		return (1);
	}
	else
		return (err_no_str(cap));
}
