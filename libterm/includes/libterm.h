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

int				setup_terminal(struct termios *saved_att);
int				reset_terminal(struct termios *saved_att);
int				execute_str(char *cap, struct termios *saved_attr);

int				err_setattr(void);
int				err_getattr(void);
int				err_noentry(void);
int				err_no_database(void);
int				err_no_env(void);
int				err_no_env(void);
int				err_no_str(char *cap);
int				err_not_terminal(void);

#endif
