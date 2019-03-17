/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_memset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:24:39 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 18:31:03 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_special_memset(t_arg *specs, char c, int len)
{
	len = max(0, len);
	realloc_if_necessary(specs, len);
	ft_memset(specs->string, (unsigned char)c, len);
	increm_string(specs, len);
}
