/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_handle_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 21:12:28 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/26 14:39:48 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"

static void	ft_putnbrbp(uintmax_t nbr, char *base, t_arg *arg, unsigned nbr_len)
{
	if (arg->got_precision)
		width_pad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}

ssize_t		handle_uint(uintmax_t nbr, t_arg *arg, char *base, char *prefix)
{
	unsigned int			nbr_len;
	unsigned int			nbrstrlen;

	if (arg->got_precision)
		arg->pad_zeroes = 0;
	nbr_len = nbrlen(nbr, base);
	if (arg->got_width && !arg->right_pad && arg->pad_zeroes)
	{
		if (arg->got_precision)
			arg->precision = ft_max(arg->width, arg->precision);
		else
			arg->precision = ft_max(arg->width, nbr_len);
		arg->got_precision = 1;
		arg->got_width = 0;
	}
	nbrstrlen = calc_nbrstrlen(nbr, base, prefix, arg);
	if (arg->got_width && !arg->right_pad)
		width_pad(nbrstrlen, arg->width, ' ');
	if (arg->force_prefix && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, base, arg, nbr_len);
	if (arg->got_width && arg->right_pad)
		width_pad(nbrstrlen, arg->width, ' ');
	return (arg->got_width ? FT_MAX(nbrstrlen, arg->width) : nbrstrlen);
}
