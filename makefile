NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

SRC = src/main.c src/parsing.c src/indexing.c src/markup.c src/push_a_b.c \
      src/cost_analysis.c src/alignment.c src/stack_utils.c src/operations.c \
      src/error.c libft_utils.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I includes/

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re