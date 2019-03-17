#include "ft_termcap.h"

char	*get_termcap_code(char *cap)
{
	char	*code;

	if (ft_strcmp(cap, "clear") == 0)
		code = ft_strdup("cl");
	else if (ft_strcmp(cap, "print_line") == 0)
		code = ft_strdup("do");
	else if (ft_strcmp(cap, "erase_endline") == 0)
			code = ft_strdup("ce");
	else if (ft_strcmp(cap, "move_cursor") == 0)
			code = ft_strdup("cm");
	else if (ft_strcmp(cap, "print_line") == 0)
		code = ft_strdup("do");
	else
		return (NULL);
	return (code);
}

int		execute_termcap(char *cap)
{
	char	buf[50];
	char	*cap_code;
	char	*cap_str;
	char	*ap;

	ap = buf;
	if ((cap_code = get_termcap_code(cap)))
		return (0);
	cap_str = tgetstr(cap_code, &ap);
	write(1, buf, strlen(cap_str));
	free(cap_code);
	return (1);
}
