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
	struct termios	saved_attr;

	if (ac < 2)
		return (err_usage());
	if (setup_terminal(&saved_attr) == 0)
		return (1);
	else
	{
		av++;
		ft_select(av);
		reset_terminal(&saved_attr);
		return (0);
	}
	return (1);
}
