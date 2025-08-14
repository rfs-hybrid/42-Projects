NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCDIR=srcs
INCDIR=includes
SRCS=$(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_swap.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "ar rcc $(NAME) $(OBJS)"
	ar rcc $(NAME) $(OBJS)

%.o: %.c $(INCDIR)/ft.h
	@echo "$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@"
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@echo "rm -f $(OBJS)"
	rm -f $(OBJS)

fclean: clean
	@echo "rm -f $(NAME)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
