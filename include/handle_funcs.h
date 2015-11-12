/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:45:58 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 15:26:52 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FUNCS_H
# define HANDLE_FUNCS_H
# include <stdarg.h>
# include "ft_printf.h"
# include <stdint.h>
# include <sys/types.h>

typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

ssize_t				ft_printf_handle_escape(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_str(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_wstr(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_ptr(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_int(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_long(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_octal(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_unsigned(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_hex(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_char(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_wchar(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_null(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_binary(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_float(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printf_handle_charswritten(char **format, va_list *a,
		t_arg *arg);
ssize_t				ft_printf_handle_uint(uintmax_t nbr, t_arg *arg, char *b,
		char *p);
typedef ssize_t		(*t_handler)(char**, va_list*, t_arg*);
t_handler			ft_printf_get_handler(char c);

#endif
