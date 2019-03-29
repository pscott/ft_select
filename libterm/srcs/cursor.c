#include "libterm.h"

static void	sanitize_pos_values(int *col, int *row)
{
	(*col)--;
	(*row)--;
	if (*col < 0)
		*col = 0;
	if (*row < 0)
		*row = 0;
}

static void	parse_pos(char *pos_str, t_pos *curr_pos)
{
	char	*col_start;

	curr_pos->row = atoi(pos_str + 2);
	col_start = strchr(pos_str, ';'); // error
	curr_pos->col = col_start ? atoi(col_start + 1) : 0;
}

static void	get_pos(char *pos_str)
{
	int	len;

	tputs(GET_POS, 1, ft_putchar);//error tputs
	if ((len = read(STDIN, pos_str, 20) > 0))//error read
		pos_str[len] = 0;
	else if (len == -1)
		term_putstr_endline("error: failed to read", 2);
}

void	retrieve_pos(t_pos *curr_pos)
{
	char	pos_str[21];

	ft_bzero(pos_str, 21);
	get_pos(pos_str);
	parse_pos(pos_str, curr_pos);
}

int		move_cursor(int col, int row)
{
	char	buf[50];
	char	*gotostr;
	char	*ap;

	sanitize_pos_values(&col, &row);//error
	ft_bzero(buf, 50);
	ap = buf;
	if (!(gotostr = tgetstr(MOVE_CURSOR, &ap)))
		return (err_no_str(MOVE_CURSOR));
	if (!(gotostr = tgoto(gotostr, col, row)))
		return (err_tgoto(MOVE_CURSOR));
	tputs(gotostr, 1, ft_putchar); //tputs error
	return (1);
}
