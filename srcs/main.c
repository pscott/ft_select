#include "ft_select.h"


static int		input_loop(t_arg_list *lst, t_print_info *info)
{
	char			buf[BUF_SIZE + 1];
	int				ret;

	while ((ret = read(STDIN_FILENO, buf, BUF_SIZE) > 0))
	{
		buf[BUF_SIZE] = 0;
		if (check_for_movement(lst, info, buf));
		else if (check_for_highlight(lst, buf));
		else if (check_for_delete(lst, info, buf));
		else if (check_for_stop(buf));
		else if (check_for_quit(lst, buf))
		{
			ret = 0;
			break ;
		}
		else if (ft_strncmp(buf, "\r", 1) == 0)
			break ;
		print_list(lst, info);
		ft_memset(buf, 0, BUF_SIZE);
	}
	execute_str(CLEAR_BELOW);
	if (ret == -1)
		term_putstr_endline("error: failed to read", 2);
	return (ret);
}

static int		ft_select(char **av)
{
	t_arg_list		*lst;
	t_print_info	info;

	lst = create_list(av);
	lst->current = 1;
	get_print_info(lst, &info);
	print_list(lst, &info);
	if (input_loop(lst, &info) < 1)
	{
		free_list(lst);
		return (0);
	}
	else
	{
		print_selected(lst);
		free_list(lst);
		return (1);
	}
}

int				main(int ac, char **av)
{
	int res;

	if (ac < 2)
		return (err_usage());
	signal_setup();
	if ((res = setup_terminal_settings()) == -1)
		return (res);
	else if (res == 0)
	{
		print_line();
		reset_terminal_settings();
		return (1);
	}
	else
	{
		execute_str(INVISIBLE);
		av++;
		if (ft_select(av))
			print_line();
		if (reset_terminal_settings())
			return (0);
		else
			return (1);
	}
}
