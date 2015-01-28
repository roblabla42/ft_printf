/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:27:36 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:30:53 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include <stdint.h>

ssize_t	handle_ptr(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	arg->length = z;
	arg->force_prefix = 1;
	return (generic_handle_unsigned(format, args, arg, "0123456789abcdef", "0x"));
}
