/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 12:42:42 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/02 15:44:04 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include <libft.h>
#include "utils.h"
#include <stdarg.h>

ssize_t	handle_float(char **format, va_list *args, t_arg *arg)
{
	float	nbr;

	(void)format;
	(void)arg;
	nbr = (float)va_arg(*args, double);
	ft_putstr("Float");
	return (0);
}
