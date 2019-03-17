/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:45:45 by pscott            #+#    #+#             */
/*   Updated: 2019/01/07 13:48:31 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strncat_move(char *src, int n, t_arg *specs)
{
	realloc_if_necessary(specs, n);
	ft_memcpy(specs->string, src, n);
	increm_string(specs, n);
}
