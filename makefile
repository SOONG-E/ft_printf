CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c			\
	   ft_printf_utils.c

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar crs $(NAME) $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re