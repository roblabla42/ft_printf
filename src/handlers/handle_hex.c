/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:14:14 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 02:02:16 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

ssize_t	ft_printf_handle_hex(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = ft_printf_get_unsigned_from_length(args, arg);
	if (**format == 'X')
		return (ft_printf_handle_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (ft_printf_handle_uint(nbr, arg, "0123456789abcdef", "0x"));
}
