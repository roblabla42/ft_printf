/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:04:06 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/29 17:10:04 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"
#include <stdint.h>

static unsigned int	nbrlen(intmax_t nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static intmax_t	get_signed_from_length(va_list *args, t_arg *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length == hh)
		nbr = (char)nbr;
	else if (arg->length == h)
		nbr = (short int)nbr;
	else if (arg->length == l)
		nbr = (long int)nbr;
	else if (arg->length == ll)
		nbr = (long long int)nbr;
	else if (arg->length == j)
		nbr = (intmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

void	ft_putnbr_precision(intmax_t nbr, t_arg *arg, unsigned nbr_len)
{
	uintmax_t	nbr_u;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr_u = -nbr;
	}
	else if (arg->got_precision && arg->precision == 0 && nbr == 0)
		return;
	else
	{
		if (arg->force_sign)
			ft_putchar('+');
		else if (arg->blank_sign)
			ft_putchar(' ');
		nbr_u = nbr;
	}
	width_pad(nbr_len, arg->precision, '0');
	ft_putnbrbase(nbr_u, "0123456789");
}

ssize_t	handle_int(char **format, va_list *args, t_arg *arg)
{
	intmax_t				nbr;
	unsigned int			nbr_len;
	unsigned int			nbrstrlen;

	(void)format;
	nbr = get_signed_from_length(args, arg);
	nbr_len = nbrlen(nbr);
	if ((arg->force_sign || arg->blank_sign) && nbr >= 0)
		nbr_len++;
	if (arg->got_width && !arg->right_pad && arg->pad_zeroes)
	{
		arg->precision = ft_max(arg->width, arg->precision);
		arg->got_precision = 1;
		arg->got_width = 0;
	}
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		nbrstrlen = 0;
	else
		nbrstrlen = arg->got_precision ? ft_max(nbr_len, arg->precision) : nbr_len;
	if (arg->got_width && !arg->right_pad)
		width_pad(nbrstrlen, arg->width, ' ');
	ft_putnbr_precision(nbr, arg, nbr_len);
	if (arg->got_width && arg->right_pad)
		width_pad(nbrstrlen, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? ft_max(nbrstrlen, arg->width) : nbrstrlen);
}
