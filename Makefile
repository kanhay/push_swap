# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:59:59 by khanhayf          #+#    #+#              #
#    Updated: 2023/05/14 10:57:36 by khanhayf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEAD = push_swap.h 

SRC = ab_push.c ab_rrotate.c push_swap.c ab_rotate.c ab_swap.c parsing.c split.c undersix.c sorted_tab.c

OBJ = ab_push.o ab_rrotate.o push_swap.o ab_rotate.o ab_swap.o parsing.o split.o undersix.o sorted_tab.o

BONUS = checker

HEAD_B = push_swap_bonus.h

SRC_B = ab_push_bonus.c ab_rrotate_bonus.c push_swap_bonus.c ab_rotate_bonus.c ab_swap_bonus.c parsing_bonus.c split_bonus.c get_next_line.c gnl_utils.c 

OBJ_B = ab_push_bonus.o ab_rrotate_bonus.o push_swap_bonus.o ab_rotate_bonus.o ab_swap_bonus.o parsing_bonus.o split_bonus.o get_next_line.o gnl_utils.o 

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BONUS) 

$(NAME) : $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ)

$(BONUS) : $(OBJ_B)
	cc $(FLAGS) $(OBJ_B) -o $(BONUS) 

%.o : %.c $(HEAD) $(HEAD_B)
	cc $(FLAGS) -c $<

clean :
	$(RM) $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all