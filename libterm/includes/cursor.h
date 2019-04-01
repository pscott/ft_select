#ifndef CURSOR_H
# define CURSOR_H

# include "libft.h"
# include <unistd.h>

# define GET_POS "\x1b\x5b\x36\x6e"
# define BEGIN_LINE "cr"
# define LEFT_CORNER "ho"
# define MOVE_CURSOR "cm"
# define SAVE_CURSOR "sc"
# define RESTORE_CURSOR "rc"
# define INVISIBLE "vi"
# define VISIBLE "ve"

typedef struct	s_pos {
	int	row;
	int	col;
}				t_pos;

void	retrieve_pos(t_pos *curr_pos);
int		move_cursor(int col, int row);

#endif
