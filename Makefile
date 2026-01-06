# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdyani <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 20:49:25 by hdyani            #+#    #+#              #
#    Updated: 2026/01/06 20:49:26 by hdyani           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = includes

MANDATORY_SRCS = src/mandatory/free.c \
				src/mandatory/ft_split.c \
				src/mandatory/init_stack.c \
				src/mandatory/input_handle1.c \
				src/mandatory/input_handle2.c \
				src/mandatory/libft_funcs.c \
				src/mandatory/operations.c \
				src/mandatory/ops_optimize.c \
				src/mandatory/push_back.c \
				src/mandatory/push_swap.c \
				src/mandatory/push_to_b.c \
				src/mandatory/sort_stack.c \
				src/mandatory/sort_utils.c \
				src/mandatory/sorted.c

BONUS_SRCS = src/bonus/checker_bonus.c \
			src/bonus/free_bonus.c \
			src/bonus/ft_split_bonus.c \
			src/bonus/init_stack_bonus.c \
			src/bonus/input_handle1_bonus.c \
			src/bonus/input_handle2_bonus.c \
			src/bonus/libft_funcs_bonus.c \
			src/bonus/operations_bonus.c \
			src/bonus/sorted_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap

CHECKER = checker

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(INCLUDES)/push_swap.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(MANDATORY_OBJS)

$(CHECKER): $(BONUS_OBJS) $(INCLUDES)/checker_bonus.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(BONUS_OBJS)

bonus: $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all re clean fclean bonus
