#include "libterm.h"

int		err_tgoto(char *cap)
{
	term_putstr_endline("error: failed to use tgoto with \"", 2);
	term_putstr_endline(cap ? cap : "(null)", 2);
	term_putstr_endline("\" cap.\n", 2);
	return (0);
}
