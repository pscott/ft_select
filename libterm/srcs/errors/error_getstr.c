#include "libterm.h"

int		err_no_str(char *cap)
{
	term_putstr_endline("error: no str corresponding to \"", 2);
	term_putstr_endline(cap ? cap : "(null)", 2);
	term_putstr_endline("\" cap.\n", 2);
	return (0);
}
