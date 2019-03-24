#ifndef CURSOR_H
# define CURSOR_H

# include "libft.h"
# include <unistd.h>

# define GET_POS "\x1b\x5b\x36\x6e"

typedef struct	s_pos {
	int	row;
	int	col;
}				t_pos;

void	retrieve_pos(t_pos *curr_pos);
int		move_cursor(int col, int row);

#endif
