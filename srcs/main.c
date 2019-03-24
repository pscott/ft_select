#include "ft_select.h"

int		ft_select(char **av)
{
	t_arg_list	*lst;

	lst = create_list(av);
	print_list(lst);
	free_list(lst);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (err_usage());
	if (setup_terminal() == 0)
		return (1);
	else
	{
		av++;
		signal_setup();
		ft_select(av);
		while(42);
		reset_terminal();
		return (0);
	}
	return (1);
}
