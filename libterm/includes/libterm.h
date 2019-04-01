#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <term.h>
# include <termios.h>
# include "libft.h"
# include "cursor.h"

# define CLEAR "cl"
# define CLEAR_BELOW "cd"
# define PRINT_LINE "do"
# define ERASE_ENDLINE "ce"
# define HIGHLIGHT "so"
# define NO_HIGHLIGHT "se"
# define UNDERLINE "us"
# define NO_UNDERLINE "ue"


# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ESC "\x1b"
# define LEFTARROW "\x1b\x5b\x44"
# define RIGHTARROW "\x1b\x5b\x43"
# define DOWNARROW "\x1b\x5b\x42"
# define UPARROW "\x1b\x5b\x41"
# define ARROW_LEN 3
# define SPACE "\x20"
# define SPACE_LEN 1
# define TAB "\x09"
# define TAB_LEN 1
# define RTAB "\x1b\x5b\x5a"
# define RTAB_LEN 3
# define ESCAPE "\x1b"
# define ESCAPE_LEN 1
# define BACKSPACE "\x7f"
# define BACKSPACE_LEN 1
# define DEL "\x1b\x5b\x33\x7e"
# define DEL_LEN 4

struct termios	g_saved_attr;

int				setup_terminal_settings(void);
int				reset_terminal_settings(void);
int				execute_str(char *cap);
int				print_line(void);
void			term_putstr_endline(char *str, int fd);

int				err_setattr(void);
int				err_resetattr(void);
int				err_getattr(void);
int				err_noentry(void);
int				err_no_database(void);
int				err_no_env(void);
int				err_no_env(void);
int				err_tgoto(char *cap);
int				err_no_str(char *cap);
int				err_not_terminal(void);

#endif
