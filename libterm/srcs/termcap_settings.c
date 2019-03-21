#include "libterm.h"

int			reset_terminal(struct termios *saved_attributes)
{
	if ((tcsetattr(0, TCSANOW, saved_attributes) == -1))
		return (err_setattr());
	return (1);
}

int			setup_terminal(struct termios *saved_attributes)
{
	char			term_buffer[2048];
	char			*termtype;
	int				res;
	struct termios	tattr;

	if ((termtype = getenv("TERM")) == NULL)
		return (err_no_env());
	if (isatty(0) == 0)
		return (err_not_terminal());
	if ((res = tgetent(term_buffer, termtype) == 0))
		return (err_noentry());
	else if (res == -1)
		return (err_no_database());
	if ((tcgetattr(0, saved_attributes) == -1))
		return (err_getattr());
	(void)tattr;
	return (1);
}
