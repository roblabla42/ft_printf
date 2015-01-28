/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:33:11 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:31:15 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"

ssize_t	handle_octal(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	return (generic_handle_unsigned(format, args, arg, "01234567", "0"));
}
