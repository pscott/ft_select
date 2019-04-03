#include "ft_select.h"

static void		fill_fg(char *res, char filetype, t_print_info *info,
		char colors[9][COLOR_SIZE + 1])
{
	char fg;

	fg = info->ls_colors[(filetype - 1) * 2];
	if ((fg < 'A' || fg > 'H') && (fg < 'a' || fg > 'h'))
		fg = 'x';
	if (fg < 'a')
	{
		ft_strncpy(res, BOLD, CONTROL_SIZE);
		fg = fg - 'A' + 'a';
	}
	else
		ft_strncpy(res, RESET, CONTROL_SIZE);
	if (fg == 'x')
		ft_strncpy(&res[CONTROL_SIZE], FG_DFL, COLOR_SIZE);
	else
		ft_strncpy(&res[CONTROL_SIZE], colors[fg - 'a'], COLOR_SIZE);
}

static void		fill_bg(char *res_bg, char filetype, t_print_info *info,
		char colors[9][COLOR_SIZE + 1])
{
	char bg;

	bg = info->ls_colors[(filetype - 1) * 2 + 1];
	if (bg < 'A' || bg > 'H' || bg < 'a' || bg > 'h')
		bg = 'x';
	if (bg == 'x')
		ft_strncpy(res_bg, BG_DFL, COLOR_SIZE);
	else
		ft_strncpy(res_bg, colors[bg - 'a'],
				COLOR_SIZE);
}

char			*get_color(char filetype, t_print_info *info)
{
	static char colors[9][COLOR_SIZE + 1] = { BLACK, RED, GREEN, YELLOW, BLUE,
		MAGENTA, CYAN, WHITE};
	char		*res;

	if (filetype < 1)
		return (NULL);
	if (!(*(info->ls_colors)))
		return (NULL);
	if (!(res = ft_strnew(CONTROL_SIZE + COLOR_SIZE * 2)))
		return (NULL);
	fill_fg(res, filetype, info, colors);
	fill_bg(&res[CONTROL_SIZE + COLOR_SIZE], filetype, info, colors);
	return (res);
}
