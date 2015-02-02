/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:14:14 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/02 15:33:51 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

ssize_t	handle_hex(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = get_unsigned_from_length(args, arg);
	if (**format == 'X')
		return (handle_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (handle_uint(nbr, arg, "0123456789abcdef", "0x"));
}
