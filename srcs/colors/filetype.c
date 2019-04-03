/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:38:08 by pscott            #+#    #+#             */
/*   Updated: 2019/04/03 22:38:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>

static char		dirletter(int mode)
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

static char		exe_letter(int mode)
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

static char		filetypeletter(int mode)
{
	char	c;

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
