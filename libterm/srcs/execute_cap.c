/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:18:34 by pscott            #+#    #+#             */
/*   Updated: 2019/04/02 12:37:43 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libterm.h"

int		ft_putchar_err(int c)
{
	if (write(STDERR, &c, 1) == -1)
		return (0);
	return (1);
}

int		execute_str(char *cap)
{
	char	buf[50];
	char	*cap_str;
	char	*ap;

	ap = buf;
	if (cap && (cap_str = tgetstr(cap, &ap)))
	{
		tputs(buf, 1, ft_putchar_err);
		return (1);
	}
	else
		return (err_no_str(cap));
}
