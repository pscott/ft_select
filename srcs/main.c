#include "ft_select.h"

int	main(int ac, char **av)
{
	struct termios	saved_attr;

	(void)ac;
	if (setup_terminal(&saved_attr) == 0)
		return (1);
	else
	{
		execute_str(av[1], &saved_attr);
		reset_terminal(&saved_attr);
		return (0);
	}
	return (1);
}
