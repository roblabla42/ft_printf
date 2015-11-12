/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:27:36 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 18:00:28 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"
#include <stdint.h>

ssize_t	ft_printf_handle_ptr(char **format, va_list *args, t_arg *arg)
{
	char		*base;
	uintmax_t	nbr;

	(void)format;
	arg->length = z;
	if (arg->got_precision)
		arg->pad_zeroes = 0;
	base = "0123456789abcdef";
	nbr = ft_printf_get_unsigned_from_length(args, arg);
	return (ft_printf_nbrforceprefix(nbr, base, arg, "0x"));
}
