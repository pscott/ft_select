/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increm_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:39:01 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 19:14:14 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	increm_string(t_arg *specs, int len)
{
	if (specs->string - specs->origin + len >= specs->mall_len - 1)
		realloc_if_necessary(specs, len);
	specs->string += len;
}
