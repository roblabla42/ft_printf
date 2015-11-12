/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 12:42:42 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 17:59:23 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include <libft.h>
#include "utils.h"
#include <stdarg.h>

ssize_t	ft_printf_handle_float(char **format, va_list *args, t_arg *arg)
{
	float	nbr;

	(void)format;
	(void)arg;
	nbr = (float)va_arg(*args, double);
	(void)nbr;
	ft_putstr("Float");
	return (0);
}
