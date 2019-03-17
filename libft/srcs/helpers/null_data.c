/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:48:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 18:27:41 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		null_data(t_arg *specs, ULL value)
{
	if (specs->precision && specs->precision_len == 0 && value == 0)
		return (1);
	return (0);
}
