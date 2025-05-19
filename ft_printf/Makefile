NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

FILES =	ft_printf.c ft_putchar_cnt.c ft_putstr_cnt.c ft_putptr_cnt.c \
		ft_putnbr_cnt.c ft_putunbr_cnt.c ft_puthex_cnt.c ft_putnbr_base.c
BFILES = ft_printf.c ft_putchar_cnt.c ft_putstr_cnt.c ft_putptr_cnt.c \
		 ft_putnbr_cnt.c ft_putunbr_cnt.c ft_puthex_cnt.c ft_flags_utils.c ft_utoa_base.c

SRC_PATH = ./srcs
BSRC_PATH = ./bsrcs

OBJ_PATH = ./objs
BOBJ_PATH = ./bobjs

INC_PATH = ./includes
LIBFT_PATH = ./libft
LIBFT =	$(LIBFT_PATH)/libft.a

SRC = $(addprefix $(SRC_PATH)/, $(FILES))
BSRC = $(addprefix $(BSRC_PATH)/, $(BFILES))

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
BOBJ = $(BSRC:$(BSRC_PATH)/%.c=$(BOBJ_PATH)/%.o)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

$(BOBJ_PATH)/%.o: $(BSRC_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

# all: $(LIBFT) $(OBJ_PATH) $(NAME)

all: bonus

bonus: $(LIBFT) $(BOBJ_PATH) $(NAME)

# $(NAME): $(OBJ)
# 	cp $(LIBFT) $(NAME)
# 	$(AR) $(NAME) $(OBJ)

$(NAME): $(BOBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BOBJ)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(BOBJ_PATH):
	mkdir -p $(BOBJ_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ) $(BOBJ) $(OBJ_PATH) $(BOBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
