#include "libterm.h"

int			reset_terminal(void)
{
	write(1, "Reset\n", 6);
	if ((tcsetattr(0, TCSANOW, &g_saved_attr) == -1))
		return (err_setattr());
	return (1);
}

int			setup_terminal(void)
{
	char			term_buffer[2048];
	char			*termtype;
	int				res;
	struct termios	tattr;

	if ((termtype = getenv("TERM")) == NULL)
		return (err_no_env());
	if (isatty(0) == 0)
		return (err_not_terminal());
	if ((res = tgetent(term_buffer, termtype)) == 0)
		return (err_noentry());
	else if (res == -1)
		return (err_no_database());
	if ((tcgetattr(0, &g_saved_attr) == -1))
		return (err_getattr());
	if ((tcgetattr(0, &tattr) == -1))
		return (err_getattr());
	tattr.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	tattr.c_oflag &= ~OPOST;
	tattr.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tattr.c_cflag &= ~(CSIZE | PARENB);
	tattr.c_cflag |= CS8; // ?*/
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &tattr);
	return (1);
}
