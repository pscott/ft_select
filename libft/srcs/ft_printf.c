/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2019/01/14 18:12:29 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		write_data(t_arg *specs, int total_len)
{
	write(1, specs->origin, total_len);
	free(specs->origin);
	free(specs);
	return (total_len);
}

int				ft_printf(const char *restrict f, ...)
{
	va_list	arg;
	t_arg	*specs;

	specs = NULL;
	va_start(arg, f);
	if (!f || !(specs = create_specs(specs)))
		return (-1);
	while (*f)
	{
		if (*f == '%' && handle_perc((char **)&f, specs, &arg))
		{
			if (specs->type == '%')
				print_perc(specs, *f);
			else
				parse_struct(specs, &arg);
		}
		else if (*f)
			ft_strncat_move((char *)f, 1, specs);
		if (*f)
			f++;
	}
	va_end(arg);
	if (specs->origin)
		return (write_data(specs, specs->string - specs->origin));
	return (0);
}
