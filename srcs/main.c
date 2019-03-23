#include "ft_select.h"

t_list_addr	*create_addr(void)
{
	t_list_addr *res; 
	if (!(res = (t_list_addr*)malloc(sizeof(*res))))
		return (NULL);
	res->head = NULL;
	res->tail = NULL;
	return (res);
}

int		ft_select(char **av)
{
	t_arg_list	*lst;
	t_list_addr	*addr;

	addr = create_addr();
	lst = create_list(av, addr);
	print_arg_list(addr);
	free_list(addr);
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
