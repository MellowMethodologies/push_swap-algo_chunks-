# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 23:44:14 by sbadr             #+#    #+#              #
#    Updated: 2023/01/08 23:45:09 by sbadr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
SRC = ft_atoi.c ft_split.c parsing.c functions.c functions2.c free_list.c\
	instructions01.c instructions02.c instructions03.c get_next_line_utils.c sort_5.c functions03.c \
	ft_strjoin.c ft_strcmp.c
BONUS = $(SRC) checker_bonus.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(BONUS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME) : $(OBJ) push_swap.c
	cc $(CFLAGS) $^ -o $(NAME)

$(NAME_BONUS) : $(OBJ_BONUS)
	cc $(CFLAGS) $^ -o $(NAME_BONUS)
	
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)

mv:
	@mkdir -p obj && mv $(OBJ) $(OBJ_BONUS) ./obj

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf ./obj

re: fclean dclean all

.PHONY: all fclean clean re bonus 