CC=cc

CFLAGS= -Wall -Werror -Wextra

INCLUDES=includes

PUSH_SWAP_SRCS= src/free.c src/ft_split.c src/init_stack.c src/input_handle1.c src/input_handle2.c \
		src/libft_funcs.c src/operations.c src/ops_optimize.c src/push_back.c src/push_swap.c \
		src/push_to_b.c src/sort_stack.c src/sort_utils.c src/sorted.c

CHECKER_SRCS= src/checker.c src/input_handle1.c src/input_handle2.c src/ft_split.c \
		src/libft_funcs.c src/init_stack.c src/operations.c src/ops_optimize.c src/sorted.c src/free.c

PUSH_SWAP_OBJS= $(PUSH_SWAP_SRCS:.c=.o)

CHECKER_OBJS= $(CHECKER_SRCS:.c=.o)

NAME=push_swap

CHECKER=checker


all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(PUSH_SWAP_OBJS)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(CHECKER_OBJS)

bonus: $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all re clean fclean bonus
