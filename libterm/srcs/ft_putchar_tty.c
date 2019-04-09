/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_tty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:59:20 by pscott            #+#    #+#             */
/*   Updated: 2019/04/06 10:15:29 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libterm.h"

int		ft_putchar_tty(int c)
{
	if (write(g_dev_tty, &c, 1) == -1)
	{
		ft_putstr_fd("write error: bad file descriptor\n", 2);
		return (0);
	}
	else
		return (1);
}
