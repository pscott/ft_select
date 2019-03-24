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
	t_arg_list	*lst;
	char		buf[BUF_SIZE + 1];
	int			ret;

	lst = create_list(av);
	lst->current = 1;
	print_list(lst);
	while ((ret = read(STDIN, buf, BUF_SIZE) > 0))
	{
		buf[BUF_SIZE] = 0;
		if (ft_strncmp(buf, "\004", 1) == 0)
			break;
		else if (ft_strncmp(buf, "\r", 1) == 0)
			print_line();
		else if (ft_strncmp(buf, RIGHTARROW, ARROW_LEN) == 0)
			ft_printf("right");
		else if (ft_strncmp(buf, LEFTARROW, ARROW_LEN) == 0)
			ft_printf("left");
		else if (ft_strncmp(buf, UPARROW, ARROW_LEN) == 0)
			ft_printf("up");
		else if (ft_strncmp(buf, DOWNARROW, ARROW_LEN) == 0)
			ft_printf("down");
	}
	if (ret == -1)
		term_putstr_endline("error: failed to read", 2);
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
		av++;
		signal_setup();
		ft_select(av);
		if (reset_terminal_settings())
			return (0);
		else
			return (1);
	}
}
