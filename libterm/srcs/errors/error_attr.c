#include "libft.h"

int		err_setattr(void)
{
	ft_putstr_fd("error: failed to set attributes\n", 2);
	return (0);
}

int		err_getattr(void)
{
	ft_putstr_fd("error: failed to get attributes\n", 2);
	return (0);
}
