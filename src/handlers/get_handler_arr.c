/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handler_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:50:54 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 17:58:12 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include <libft.h>

static void	setup_arr(t_handler *handlers)
{
	handlers['%'] = &ft_printf_handle_escape;
	handlers['s'] = &ft_printf_handle_str;
	handlers['S'] = &ft_printf_handle_wstr;
	handlers['p'] = &ft_printf_handle_ptr;
	handlers['d'] = &ft_printf_handle_int;
	handlers['D'] = &ft_printf_handle_long;
	handlers['i'] = &ft_printf_handle_int;
	handlers['o'] = &ft_printf_handle_octal;
	handlers['O'] = &ft_printf_handle_long;
	handlers['u'] = &ft_printf_handle_unsigned;
	handlers['U'] = &ft_printf_handle_long;
	handlers['x'] = &ft_printf_handle_hex;
	handlers['X'] = &ft_printf_handle_hex;
	handlers['c'] = &ft_printf_handle_char;
	handlers['C'] = &ft_printf_handle_wchar;
	handlers['b'] = &ft_printf_handle_binary;
	handlers['f'] = &ft_printf_handle_float;
	handlers['n'] = &ft_printf_handle_charswritten;
}

t_handler	ft_printf_get_handler(char c)
{
	static t_handler	*handlers = NULL;

	if (handlers == NULL)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 256);
		if (handlers != NULL)
			setup_arr(handlers);
	}
	return (handlers[(int)c]);
}
