/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:34:34 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:31:25 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include <stddef.h>

ssize_t	handle_unsigned(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	return (generic_handle_unsigned(format, args, arg, "0123456789", NULL));
}

