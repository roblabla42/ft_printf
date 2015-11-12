/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:48:30 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 18:00:02 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "ft_printf.h"
#include <libft.h>
#include "utils.h"

ssize_t	ft_printf_handle_null(char **format, va_list *args, t_arg *arg)
{
	(void)args;
	if (arg->got_width && !arg->right_pad)
		ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putchar(**format);
	if (arg->got_width && arg->right_pad)
		ft_printf_width_pad(1, arg->width, ' ');
	return (arg->got_width ? ft_max(arg->width, 1) : 1);
}
