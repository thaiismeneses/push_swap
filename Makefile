# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:52:31 by thfranco          #+#    #+#              #
#    Updated: 2024/03/13 14:05:23 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

SRCS		:= main.c\
				list.c\
				param_checker.c\
				check_sort.c\
				moviments.c\
				operations_a.c\
				operations_b.c\
				operations_both.c\
				a_treating_nodes.c\
				b_treating_nodes.c\
				sort.c\

OBJS		:= $(SRCS: .c=.o)

CC		:= cc

FLAGS		:= -Wall -Wextra -Werror -g -fsanitize=address 

LIBS		:= libraries/libft/libft.a  libraries/ft_printf/libftprintf.a

RM		:= rm -rf

AR		:= ar rcs

LEAK		:= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

all:	$(NAME)

$(NAME): $(OBJS)
		@echo "Compilation of $(NAME)!!!"
		@make -s bonus -C libraries/libft/
		@make -s -C libraries/ft_printf/
		@$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)
		@echo "$(NAME) created!!✔️ "

clean:
		@echo "Deleting $(NAME) objs!✔️ "
		@make -s clean -C libraries/libft/
		@make -s clean -C libraries/ft_printf/
		@$(RM) $(OBJS)

fclean:
		@echo "Deleting $(NAME)!! ✔️ "
		@make -s fclean -C libraries/libft/
		@make -s fclean -C libraries/ft_printf/
		@$(RM) $(NAME)
		@$(RM) $(LIBFT)
		@$(RM) $(LIBFTPRINT)

re:		fclean all

leak:
		$(LEAK) ./push_swap 1 2 3  

norma:
		norminette $(SRCS) push_swap.h ./libraries

.PHONY:		all clean fclean re leak norma



