# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 20:41:16 by thfranco          #+#    #+#              #
#    Updated: 2023/11/07 11:10:32 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_checker.c \
	ft_printchar.c \
	ft_printstr.c \
	ft_printnbr.c \
	ft_printud.c \
	ft_printhexa.c \
	ft_printpointer.c \
	ft_strchr.c \
	ft_printf.c\

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

AR = ar rcs

CC_FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean 
		$(RM) $(NAME)

re:	fclean all 

.PHONY: all clean fclean re 
