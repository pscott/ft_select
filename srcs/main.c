#include "ft_select.h"

static int		ft_select(char **av)
{
	t_arg_list	*lst;

	lst = create_list(av);
	print_list(lst);
	free_list(lst);
	return (1);
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
		reset_terminal_settings();
		return (0);
	}
	return (1);
}
