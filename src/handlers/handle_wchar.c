/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:42:37 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/26 14:47:21 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

ssize_t	handle_wchar(char **format, va_list *args, t_arg *arg)
{
	wchar_t		chr;
	unsigned	chr_len;

	(void)format;
	chr = (wchar_t)va_arg(*args, wint_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->got_width && !arg->right_pad)
		width_pad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->got_width && arg->right_pad)
		width_pad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? FT_MAX(chr_len, arg->width) : chr_len);
}
