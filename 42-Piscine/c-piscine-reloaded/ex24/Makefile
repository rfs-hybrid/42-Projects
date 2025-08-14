NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCDIR = ./srcs
INCDIR = ./includes
SRC = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_swap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "ar rcc $(NAME) $(OBJ)"
	ar rcc $(NAME) $(OBJ)

%.o: %.c $(INCDIR)
	@echo "$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@"
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@echo "$(RM) $(OBJ)"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(RM) $(NAME)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
