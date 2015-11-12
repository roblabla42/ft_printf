/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:33:11 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 18:00:15 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"
#include <stdlib.h>
#include <libft.h>

ssize_t	ft_printf_handle_octal(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_get_unsigned_from_length(args, arg);
	if (arg->force_prefix && nbr == 0 &&
				arg->got_precision && arg->precision == 0)
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putstr("0");
		if (arg->got_width && arg->right_pad)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->force_prefix && nbr != 0)
	{
		arg->got_precision = 1;
		arg->precision = ft_max(arg->precision,
				ft_printf_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_printf_handle_uint(nbr, arg, "01234567", NULL));
}
