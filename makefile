NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

SRCS = srcs/main.c srcs/get_argument_control.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re