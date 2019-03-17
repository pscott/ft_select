/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:47:31 by pscott            #+#    #+#             */
/*   Updated: 2019/01/06 19:29:38 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_data_len(t_arg *specs, LL value)
{
	if (specs->type == 'x')
		value_x(specs, value);
	else if (specs->type == 'X')
		value_xx(specs, value);
	else if (specs->type == 'o')
		value_o(specs, value);
}
