# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/11/12 18:08:13 by roblabla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_INCLUDE_PATH += include/ libft/include

CFLAGS += -Wall -Wextra -Werror

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

SRCS = src/ft_printf.c \
	   src/parse_handlers.c \
	   src/utils/get_unsigned_from_length.c \
	   src/utils/width_pad.c \
	   src/utils/nbrlen.c \
	   src/utils/calc_nbrstrlen.c \
	   src/utils/nbrforceprefix.c \
	   src/handlers/get_handler_arr.c \
	   src/handlers/generic_handle_unsigned.c \
	   src/handlers/handle_null.c \
	   src/handlers/handle_char.c \
	   src/handlers/handle_escape.c \
	   src/handlers/handle_hex.c \
	   src/handlers/handle_int.c \
	   src/handlers/handle_long.c \
	   src/handlers/handle_octal.c \
	   src/handlers/handle_ptr.c \
	   src/handlers/handle_str.c \
	   src/handlers/handle_unsigned.c \
	   src/handlers/handle_wchar.c \
	   src/handlers/handle_binary.c \
	   src/handlers/handle_charswritten.c \
	   src/handlers/handle_float.c \
	   src/handlers/handle_wstr.c

LIBFT_FUNS =	strchr \
				putstr \
				strlen \
				putnstr \
				bzero \
				isdigit \
				memalloc \
				putchar \
				max \
				tolower \
				nstrlen \
				putwchar \
				putnwstr \
				putnbrbase \

LIBFT_CFLAGS += $(foreach fun,$(LIBFT_FUNS),-Dft_$(fun)=ft_printf_libft_$(fun))
LIBFT_CFLAGS += -Ilibft/include

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
OBJS += $(foreach fun,$(LIBFT_FUNS),obj/libft/ft_$(fun).o)

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@
	@mkdir -p $@/handlers
	@mkdir -p $@/utils
	@mkdir -p $@/libft

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

obj/libft/%.o: libft/%.c
	$(CC) -c $(LIBFT_CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)

libfttest: $(NAME) obj/main.o
	$(CC) -o $@ obj/main.o -L. -lftprintf

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf obj

re: fclean all

.PHONY: all clean fclean re
