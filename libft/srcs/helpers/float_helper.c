/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:54:10 by pscott            #+#    #+#             */
/*   Updated: 2019/01/07 16:21:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_i(t_arg *specs)
{
	int i;

	if (specs->precision)
		if (specs->precision_len)
		{
			i = specs->precision_len;
			ft_special_memset(specs, '.', 1);
		}
		else
			i = 0;
	else
	{
		i = 6;
		ft_special_memset(specs, '.', 1);
	}
	return (i);
}
