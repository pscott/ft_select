#include "ft_select.h"

int	main(void)
{
	struct termios	saved_attr;

	if (setup_terminal(&saved_attr) == 0)
		return (1);
	else
	{
		if (execute_termcap(CLEAR, &saved_attr))
		{
			reset_terminal(&saved_attr);
			return (0);
		}
		return (1);
	}
}
