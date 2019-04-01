#include "ft_select.h"

/*static void		magic_print(char *buf)
  {
  while (*buf)
  {
  ft_printf("%d ", *buf);
  buf++;
  }
  }*/

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
	while ((ret = read(STDIN_FILENO, buf, BUF_SIZE) > 0))
	{
		buf[BUF_SIZE] = 0;
		if (ft_strncmp(buf, SPACE, SPACE_LEN) == 0)
			highlight_node(lst);
		else if (ft_strncmp(buf, "\r", 1) == 0)
			break ;
		else if (ft_strncmp(buf, RIGHTARROW, ARROW_LEN) == 0)
			move_horizontally(lst, &info, "right");
		else if (ft_strncmp(buf, LEFTARROW, ARROW_LEN) == 0)
			move_horizontally(lst, &info, "left");
		else if (ft_strncmp(buf, UPARROW, ARROW_LEN) == 0 || ft_strncmp(buf, RTAB, RTAB_LEN) == 0)
			move_vertically(lst, "up");
		else if (ft_strncmp(buf, DOWNARROW, ARROW_LEN) == 0 || ft_strncmp(buf, TAB, TAB_LEN) == 0)
			move_vertically(lst, "down");
		else if (ft_strncmp(buf, BACKSPACE, BACKSPACE_LEN) == 0 || ft_strncmp(buf, DEL, DEL_LEN) == 0)
		{
			if (info.nb_elem == 1)
			{
				execute_str(CLEAR_BELOW);
				return (0);
			}
			else
				lst = delete_node(lst, &info);
		}
		else if (ft_strncmp(buf, "\x04", 1) == 0 || ft_strncmp(buf, ESCAPE, ESCAPE_LEN + 1) == 0)
		{
			reset_lst(lst);
			break;
		}
		else if (ft_strncmp(buf, "\x1a", 1) == 0)
			sigtstp_handler(SIGTSTP);
		print_list(lst, &info);
		ft_memset(buf, 0, BUF_SIZE);
	}
	execute_str(CLEAR_BELOW);
	if (ret == -1)
	{
		term_putstr_endline("error: failed to read", 2);
		free_list(lst);
		return (0);
	}
	else if (ft_strncmp(buf, "\004", 1) == 0 || ft_strncmp(buf, ESCAPE, ESCAPE_LEN) == 0)
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
	signal_setup();
	if (ac < 2)
		return (err_usage());
	if (setup_terminal_settings() == 0)
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
