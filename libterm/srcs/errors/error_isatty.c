/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_isatty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:54:40 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 14:54:40 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		err_not_terminal(void)
{
	ft_putstr_fd("error: not a terminal.\n", 2);
	return (0);
}
