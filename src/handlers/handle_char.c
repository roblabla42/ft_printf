/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:09:51 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 17:59:02 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

ssize_t	ft_printf_handle_char(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	if (arg->length == l)
		return (ft_printf_handle_wchar(format, args, arg));
	else
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->got_width && arg->right_pad)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
}
