#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <term.h>
# include <termios.h>
# include "libft.h"

# define CLEAR "cl"
# define PRINT_LINE "do"
# define ERASE_ENDLINE "ce"
# define MOVE_CURSOR "cm"

typedef struct	s_pos {
				int	row;
				int	col;
}				t_pos;

struct termios	g_saved_attr;

int				setup_terminal(void);
int				reset_terminal(void);
int				execute_str(char *cap);

int				err_setattr(void);
int				err_getattr(void);
int				err_noentry(void);
int				err_no_database(void);
int				err_no_env(void);
int				err_no_env(void);
int				err_no_str(char *cap);
int				err_not_terminal(void);

#endif
