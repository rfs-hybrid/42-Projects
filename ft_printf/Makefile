NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
FILES =	ft_printf.c ft_putchar_cnt.c ft_putstr_cnt.c ft_putptr_cnt.c \
		ft_putnbr_cnt.c ft_putunbr_cnt.c ft_puthex_cnt.c ft_putnbr_base.c
SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = ./includes
LIBFTDIR = ./libft
LIBFT =	$(LIBFTDIR)/libft.a
SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

all: $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFTDIR) all

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJ) $(OBJDIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
