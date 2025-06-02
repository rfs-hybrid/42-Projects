NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

FILES = ft_printf.c ft_putchar_cnt.c ft_putstr_cnt.c \
		ft_putptr_cnt.c ft_putnbr_cnt.c ft_putunbr_cnt.c \
		ft_puthex_cnt.c ft_flags_utils.c ft_utoa_base.c

SRC_PATH = ./srcs

OBJ_PATH = ./objs

INC_PATH = ./includes
LIBFT_PATH = ./libft
LIBFT =	$(LIBFT_PATH)/libft.a

SRC = $(addprefix $(SRC_PATH)/, $(FILES))

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all: $(LIBFT) $(OBJ_PATH) $(NAME)

bonus: all

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ) $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
