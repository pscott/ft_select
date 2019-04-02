/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:18:39 by pscott            #+#    #+#             */
/*   Updated: 2019/04/02 12:38:44 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libterm.h"

int			reset_terminal_settings(void)
{
	if (isatty(STDIN) == 0)
		return (0);
	execute_str(VISIBLE);
	if ((tcsetattr(STDIN, TCSANOW, &g_saved_attr) == -1))
		return (err_resetattr());
	return (1);
}

int			set_non_canonical_mode(struct termios *tattr)
{
	tattr->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR
			| ICRNL | IXON);
	tattr->c_oflag &= ~OPOST;
	tattr->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tattr->c_cflag &= ~(CSIZE | PARENB);
	tattr->c_cflag |= CS8;
	tattr->c_cc[VMIN] = 1;
	tattr->c_cc[VTIME] = 0;
	if (tcsetattr(STDIN, TCSAFLUSH, tattr) == -1)
		return (err_setattr());
	return (1);
}

int			setup_terminal_settings(void)
{
	char			term_buffer[2048];
	char			*termtype;
	int				res;
	struct termios	tattr;

	if ((termtype = getenv("TERM")) == NULL)
		return (err_no_env());
	if (isatty(STDIN) == 0)
		return (err_not_terminal());
	if ((res = tgetent(term_buffer, termtype)) == 0)
		return (err_noentry());
	else if (res == -1)
		return (err_no_database());
	if ((tcgetattr(STDIN, &g_saved_attr) == -1))
		return (err_getattr());
	if ((tcgetattr(STDIN, &tattr) == -1))
		return (err_getattr());
	if (set_non_canonical_mode(&tattr) == 0)
		return (0);
	return (1);
}
