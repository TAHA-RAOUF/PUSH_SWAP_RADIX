
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror


SRCS = push_swap.c helper_function.c helper_function2.c helper_function3.c moves.c moves2.c moves3.c sort_small.c  rank_algo.c radix_algo.c
OBJECTS = $(SRCS:.c=.o)


NAME = push_swap


all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)


%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.SECONDARY : $(OBJECTS)

.PHONY: all clean fclean re
