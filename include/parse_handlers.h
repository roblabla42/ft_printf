/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 20:02:58 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 01:50:14 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HANDLERS_H
# define PARSE_HANDLERS_H
# include "handle_funcs.h"

char	*ft_printf_parse_flags(char **format, t_arg *arg);
char	*ft_printf_parse_width(char **format, va_list *list, t_arg *arg);
char	*ft_printf_parse_precision(char **format, va_list *list, t_arg *arg);
char	*ft_printf_parse_length(char **format, t_arg *arg);
#endif
