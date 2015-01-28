/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:03:42 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:05:52 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <inttypes.h>

uintmax_t	get_unsigned_from_length(va_list *args, t_arg *arg);
void	width_pad(int nbrstrlen, int width, char padwith);
#endif
