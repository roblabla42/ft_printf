/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_handle_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 21:12:28 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/29 17:43:02 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

static unsigned int	nbrlen(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_nbr;
		i++;
	}
	return (i);
}

static void	ft_putnbrbase_precision(intmax_t nbr, char *base, char **format, t_arg *arg, unsigned nbr_len)
{
	if (arg->got_precision)
		width_pad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->got_precision && arg->precision == 0 && ft_tolower(**format) != 'o')
		return;
	else
		ft_putnbrbase(nbr, base);
}

ssize_t	generic_handle_unsigned(char **format, va_list *args, t_arg *arg, char *base, char *prefix)
{
	uintmax_t				nbr;
	unsigned int			nbr_len;
	unsigned int			nbrstrlen;

	nbr = get_unsigned_from_length(args, arg);
	nbr_len = nbrlen(nbr, base);
	if (arg->got_width && !arg->right_pad && arg->pad_zeroes)
	{
		arg->precision = ft_max(arg->width, arg->precision);
		arg->got_precision = 1;
		arg->got_width = 0;
	}
	if (!arg->pad_zeroes && arg->force_prefix && prefix != NULL && (nbr != 0 || **format == 'p'))
		nbr_len += ft_strlen(prefix);
	if (nbr == 0 && arg->got_precision && arg->precision == 0 && ft_tolower(**format) != 'o')
		if (!arg->pad_zeroes && arg->force_prefix && prefix != NULL && (nbr != 0 || **format == 'p'))
			nbrstrlen = ft_strlen(prefix);
		else
			nbrstrlen = 0;
	else
		nbrstrlen = arg->got_precision ? ft_max(nbr_len, arg->precision) : nbr_len;
	if (arg->pad_zeroes && arg->force_prefix && prefix != NULL && (nbr != 0 || **format == 'p'))
		nbrstrlen += ft_strlen(prefix);
	if (arg->got_width && !arg->right_pad)
		width_pad(nbrstrlen, arg->width, ' ');
	if (arg->force_prefix && prefix != NULL && (nbr != 0 || **format == 'p'))
		ft_putstr(prefix);
	ft_putnbrbase_precision(nbr, base, format, arg, nbr_len);
	if (arg->got_width && arg->right_pad)
		width_pad(nbrstrlen, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? ft_max(nbrstrlen, arg->width) : nbrstrlen);
}
