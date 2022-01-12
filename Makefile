# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:22:34 by lfranca-          #+#    #+#              #
#    Updated: 2022/01/12 14:44:21 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	=	./libft/libft.a

SRC		=	push_act.c rotate_swap_act.c small_sorts.c atoi_long.c\
			free_elements.c push_swap_main.c send_to_sort.c simplify_numbers.c\
			verify_errors.c radix_sort.c\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

INC		=	-I ./libft -I ./

LIB		=	-L ./libft -lft

HEADERS	=	./push_swap.h ./libft/libft.h

all:	$(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(INC) $(LIB) -o $@

$(LIBFT):
	@make -s -C libft
	@echo "Libft compiled!"

clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ)
	@echo "object files removed."

fclean:		clean
	@make -s $@ -C libft
	@rm -rf $(NAME)
	@echo "binary files removed."

re:		fclean all

.PHONY:		all clean fclean re
