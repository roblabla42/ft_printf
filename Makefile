# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/02/26 15:08:08 by roblabla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_INCLUDE_PATH += libft/include/ include/

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

LIBFT_PATH ?= libft/

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@
	@mkdir -p $@/handlers
	@mkdir -p $@/utils

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS)
	$(CP) $(LIBFT_PATH)/libft.a $(NAME)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

libfttest: $(NAME) obj/main.o
	$(CC) -o $@ $^

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all


.PHONY: all clean fclean re $(LIBFT_PATH)/libft.a
