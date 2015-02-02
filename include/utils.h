/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:03:42 by rlambert          #+#    #+#             */
/*   Updated: 2015/02/02 17:25:26 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <inttypes.h>
# include "handle_funcs.h"

uintmax_t		get_unsigned_from_length(va_list *args, t_arg *arg);
void			width_pad(int nbrstrlen, int width, char padwith);
unsigned int	nbrlen(uintmax_t nbr, char *base);
unsigned int	calc_nbrstrlen(uintmax_t nbr, char *base, char *p, t_arg *arg);
ssize_t			nbrforceprefix(uintmax_t n, char *b, t_arg *a, char *p);
#endif
