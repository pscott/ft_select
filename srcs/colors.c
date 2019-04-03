#include "ft_select.h"
#include <sys/stat.h>

static char dirletter(int mode)
{
	char c;
	if (mode & S_IWOTH)
	{
		if (mode & S_ISVTX)
			c = 10;
		else
			c = 11;
	}
	else
		c = 1;
	return (c);
}

static char exe_letter(int mode)
{
	char c;

	if (mode & S_ISUID)
		c = 8;
	else if (mode & S_ISGID)
		c = 9;
	else
		c = 5;
	return (c);
}

static char filetypeletter(int mode)
{
	char    c;

	if (S_ISDIR(mode))
		c = dirletter(mode);
	else if (S_ISLNK(mode))
		c = 2;
	else if (S_ISSOCK(mode))
		c = 3;
	else if (S_ISFIFO(mode))
		c = 4;
	else if (mode & S_IXUSR)
		c = exe_letter(mode);
	else if (S_ISBLK(mode))
		c = 6;
	else if (S_ISCHR(mode))
		c = 7;
	else
		c = 0;
	return (c);
}

char			get_file_type(char *name)
{
	struct stat buf;

	if (lstat(name, &buf) < 0)
		return (0);
	else
		return (filetypeletter(buf.st_mode));
}

/*
 ** all bold colors treated as non bold
 */

char			*get_color(char	filetype, t_print_info *info)
{
	static char colors[9][COLOR_SIZE + 1] = { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
	char	*res;
	char	fg;
	char	bg;

	if (!(res = ft_strnew(CONTROL_SIZE + COLOR_SIZE * 2 + 1)))
		return (NULL);
	if (filetype < 1)
		return (NULL);
	if (!(*(info->ls_colors)))
		return (NULL);
	fg = info->ls_colors[(filetype - 1) * 2];
	bg = info->ls_colors[(filetype - 1) * 2 + 1];
	//sanitize bg and fg ?
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
	ft_strncpy(&res[CONTROL_SIZE + COLOR_SIZE], BG_DFL, COLOR_SIZE);
	if (bg == 'x')
		ft_strncpy(&res[CONTROL_SIZE + COLOR_SIZE], BG_DFL, COLOR_SIZE);
	else
		ft_strncpy(&res[CONTROL_SIZE + COLOR_SIZE],  colors[bg - 'a'], COLOR_SIZE);
	return (res);
}
