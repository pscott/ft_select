#include "ft_select.h"

static void		magic_print(char *buf)
{
	while (*buf)
	{
		ft_printf("%d ", *buf);
		buf++;
	}
}

static int		ft_select(char **av)
{
	t_arg_list		*lst;
	char			buf[BUF_SIZE + 1];
	int				ret;
	t_print_info	info;

	lst = create_list(av);
	lst->current = 1;
	get_print_info(lst, &info);
	print_list(lst, &info);
	while ((ret = read(STDIN, buf, BUF_SIZE) > 0))
	{
		buf[BUF_SIZE] = 0;
		if (ft_strncmp(buf, "\004", 1) == 0)
			break ;
		else if (ft_strncmp(buf, "a", 1) == 0)
		{
			if (ioctl(STDOUT, TIOCSTI, "\x1A") == -1)
				ft_printf("aie");
		}
		else if (ft_strncmp(buf, SPACE, SPACE_LEN) == 0)
			select_node(lst, &info);
		else if (ft_strncmp(buf, "\r", 1) == 0)
			break ;
		else if (ft_strncmp(buf, RIGHTARROW, ARROW_LEN) == 0)
			move_horizontally(lst, &info, "right");
		else if (ft_strncmp(buf, LEFTARROW, ARROW_LEN) == 0)
			move_horizontally(lst, &info, "left");
		else if (ft_strncmp(buf, UPARROW, ARROW_LEN) == 0 || ft_strncmp(buf, RTAB, RTAB_LEN) == 0)
			move_vertically(lst, &info, "up");
		else if (ft_strncmp(buf, DOWNARROW, ARROW_LEN) == 0 || ft_strncmp(buf, TAB, TAB_LEN) == 0)
			move_vertically(lst, &info, "down");
	}
	if (ret == -1)
		term_putstr_endline("error: failed to read", 2);
	execute_str(CLEAR_BELOW);
	print_selected(lst, &info);
	free_list(lst);
	return (0);
}

int				main(int ac, char **av)
{
	if (ac < 2)
		return (err_usage());
	if (setup_terminal_settings() == 0)
	{
		reset_terminal_settings();
		return (1);
	}
	else
	{
		execute_str(INVISIBLE);
		av++;
		signal_setup();
		ft_select(av);
		if (reset_terminal_settings())
			return (0);
		else
			return (1);
	}
}
