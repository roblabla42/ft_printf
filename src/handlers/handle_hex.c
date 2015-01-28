/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:14:14 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:31:08 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"

ssize_t	handle_hex(char **format, va_list *args, t_arg *arg)
{
	if (**format == 'X')
		return (generic_handle_unsigned(format, args, arg, "0123456789ABCDEF", "0X"));
	else
		return (generic_handle_unsigned(format, args, arg, "0123456789abcdef", "0x"));
}
