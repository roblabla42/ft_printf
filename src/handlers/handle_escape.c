/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:48:13 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 17:34:07 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include <libft.h>

ssize_t	handle_escape(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	ft_putchar('%');
	return (1);
}
