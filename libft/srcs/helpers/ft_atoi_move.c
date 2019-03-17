/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:42:16 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 18:05:25 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_move(char **str)
{
	int		finalnb;

	finalnb = 0;
	while (ft_isdigit(**str))
	{
		finalnb = finalnb * 10 + **str - '0';
		(*str)++;
	}
	return (finalnb);
}
