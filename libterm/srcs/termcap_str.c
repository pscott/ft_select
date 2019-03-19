#include "libterm.h"

int		execute_termcap(char *cap, struct termios *saved_attr)
{
	char	buf[50];
	char	*cap_str;
	char	*ap;

	if (!cap)
		return (err_no_str(cap));
	ap = buf;
	if ((cap_str = tgetstr(cap, &ap)))
	{
		write(1, buf, strlen(cap_str)); //tputs ?
		return (1);
	}
	else
		return (err_no_str(cap));
}
