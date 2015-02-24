/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handler_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:50:54 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/19 19:14:47 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include <libft.h>

static void	setup_arr(t_handler *handlers)
{
	handlers['%'] = &handle_escape;
	handlers['s'] = &handle_str;
	handlers['S'] = &handle_wstr;
	handlers['p'] = &handle_ptr;
	handlers['d'] = &handle_int;
	handlers['D'] = &handle_long;
	handlers['i'] = &handle_int;
	handlers['o'] = &handle_octal;
	handlers['O'] = &handle_long;
	handlers['u'] = &handle_unsigned;
	handlers['U'] = &handle_long;
	handlers['x'] = &handle_hex;
	handlers['X'] = &handle_hex;
	handlers['c'] = &handle_char;
	handlers['C'] = &handle_wchar;
	handlers['b'] = &handle_binary;
	handlers['f'] = &handle_float;
	handlers['n'] = &handle_charswritten;
}

t_handler	get_handler(char c)
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
