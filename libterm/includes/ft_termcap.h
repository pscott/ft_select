#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <termios.h>
# include <term.h>
# include "libft.h"

typedef struct	s_pos {
				int	row;
				int	col;
}				t_pos;

char			*get_termcap_code(char *cap);
int				execute_termcap(char *cap);

#endif
