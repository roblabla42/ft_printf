/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:42:28 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/26 14:41:41 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "utils.h"
#include <libft.h>
#include <wchar.h>

ssize_t	handle_str(char **format, va_list *args, t_arg *arg)
{
	char	*str;
	size_t	strlen;

	if (arg->length == l)
		return (handle_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		strlen = arg->got_precision ? ft_nstrlen(str, arg->precision) :
				ft_strlen(str);
		if (arg->got_width && !arg->right_pad)
			width_pad(strlen, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putnstr(str, strlen);
		if (arg->got_width && arg->right_pad)
			width_pad(strlen, arg->width, ' ');
		return (arg->got_width ? FT_MAX(strlen, arg->width) : strlen);
	}
}
