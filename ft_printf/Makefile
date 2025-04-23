NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = ./includes
LIBFTDIR = ./libft
LIBFT =	$(LIBFTDIR)/libft.a
SRC =	$(SRCDIR)/ft_printf.c $(SRCDIR)/ft_putchar_cnt.c $(SRCDIR)/ft_putstr_cnt.c \
		$(SRCDIR)/ft_putptr_cnt.c $(SRCDIR)/ft_putnbr_cnt.c $(SRCDIR)/ft_putunbr_cnt.c \
		$(SRCDIR)/ft_puthex_cnt.c $(SRCDIR)/ft_putnbr_base.c
OBJ = $(SRC:%.c=%.o)

%.o: %.c $(INCDIR)/ft_printf.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

all: $(LIBFT) $(NAME) $(OBJDIR)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFTDIR) all

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mv $(OBJ) $(OBJDIR)

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJ) $(OBJDIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
