SRCS = ft_strlen.c ft_putstr_fd.c ft_strdup.c \
	ft_isdigit.c ft_atoi.c ft_split.c

PRINTF_DIR = ft_printf
PRINTF_FILES = ft_printf.c srcs/ft_putchar.c srcs/ft_putstr.c \
	srcs/ft_puthexa.c srcs/ft_putptr.c srcs/ft_putint.c srcs/ft_putuint.c

SRCS += $(addprefix $(PRINTF_DIR)/,$(PRINTF_FILES))

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
