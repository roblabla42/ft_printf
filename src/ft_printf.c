/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:40:59 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/17 18:09:22 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "parse_handlers.h"

static ssize_t	handle_arg(char **format, va_list *args, t_arg *sarg)
{
	ssize_t		ret;
	t_handler	handler;

	if ((*(++*format)) == '\0')
		return (0);
	if ((parse_flags(format, sarg)) == NULL)
		return (-1);
	if ((parse_width(format, args, sarg)) == NULL)
		return (-1);
	if ((parse_precision(format, args, sarg)) == NULL)
		return (-1);
	if ((parse_length(format, sarg)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (get_handler(**format) == NULL)
		handler = handle_null;
	else
		handler = get_handler(**format);
	ret = handler(format, args, sarg);
	(*format)++;
	return (ret);
}

static int		ft_inner_printf(const char *format, va_list *args, size_t chrs)
{
	char	*next_arg;
	t_arg	sarg;
	ssize_t	handler_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (chrs);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (chrs + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_inner_printf(next_arg, args, chrs + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));
		if ((handler_len = handle_arg((char**)&format, args, &sarg)) == -1)
			return (-1);
		else
			return (ft_inner_printf(format, args, chrs + handler_len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_inner_printf(format, &args, 0);
	va_end(args);
	return (ret);
}
