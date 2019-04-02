/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_getenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:18:51 by pscott            #+#    #+#             */
/*   Updated: 2019/04/02 12:18:51 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		err_no_env(void)
{
	ft_putstr_fd("error: no TERM variable found in environment.\n", 2);
	return (0);
}
