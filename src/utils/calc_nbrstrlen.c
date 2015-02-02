/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbrstrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 18:45:25 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/02 17:23:30 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <libft.h>
#include "handle_funcs.h"
#include "utils.h"

unsigned int	calc_nbrstrlen(uintmax_t nbr, char *base, char *p, t_arg *arg)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbr_len = nbrlen(nbr, base);
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->got_precision)
		nbrstrlen = ft_max(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->force_prefix && p != NULL && nbr != 0)
		nbrstrlen += ft_strlen(p);
	return (nbrstrlen);
}
