# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emanuele <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 00:13:19 by emanuele          #+#    #+#              #
#    Updated: 2021/11/11 00:17:03 by emanuele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
SRCS = ft_printf.c ft_putchar_len.c ft_nbr.c ft_str.c ft_uxxp.c
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
