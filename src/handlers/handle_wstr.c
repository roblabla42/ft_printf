/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:43:43 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:13:30 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

size_t	calc_wstrlen(wchar_t *str, int precision)
{
	size_t i;

	i = 0;
	while (*str && precision > 0)
	{
		if (*str <= 0x7F)
		{
			i++;
			precision--;
		}
		else if (*str <= 0x7FF && precision >= 2)
		{
			i += 2;
			precision -= 2;
		}
		else if (*str <= 0xFFFF && precision >= 3)
		{
			i += 3;
			precision -= 3;
		}
		else if (*str <= 0x10FFFF && precision >= 4)
		{
			i += 4;
			precision -= 4;
		}
		str++;
	}
	return (i);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t	handle_wstr(char **format, va_list *args, t_arg *arg)
{
	wchar_t	*str;
	size_t	strlen;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = arg->got_precision ? calc_wstrlen(str, arg->precision) :
			ft_wstrlen(str);
	if (arg->got_width && !arg->right_pad)
		width_pad(strlen, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putnwstr(str, strlen);
	if (arg->got_width && arg->right_pad)
		width_pad(strlen, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? ft_max(strlen, arg->width) : strlen);
}
