/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:24:55 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/17 18:14:08 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "ft_printf.h"
#include <libft.h>

ssize_t	handle_long(char **format, va_list *args, t_arg *arg)
{
	arg->length = l;
	return (get_handler(ft_tolower(**format))(format, args, arg));
}
