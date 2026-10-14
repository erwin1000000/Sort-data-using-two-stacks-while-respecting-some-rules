NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
       operations.c \
       operations_help.c \
       sorting_algorithm.c \
       sorting_algorithm_help.c \
       sorting_algorithm_help2.c \
       check_input.c\
       ft_atoi.c\
       lincked_list_fonctions.c\
       operations_help2.c\
       sorting_algorithm_help1.c\
       split_3d_array.c\
       split_3d_array_help.c\
       stack_creation.c\
       the_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
