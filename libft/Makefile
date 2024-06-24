SRCS = ft_putchar.c ft_putstr.c ft_strlen.c ft_atoi.c ft_split.c ft_isdigit.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@cc $(CFLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
