#include "libterm.h"

int		execute_str(char *cap, struct termios *saved_attr)
{
	char	buf[50];
	char	*cap_str;
	char	*ap;

	ap = buf;
	if (cap && (cap_str = tgetstr(cap, &ap)))
	{
		write(1, buf, strlen(cap_str)); //tputs ?
		return (1);
	}
	else
		return (err_no_str(cap));
}
