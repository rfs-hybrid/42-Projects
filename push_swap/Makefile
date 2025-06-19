NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ift_printf/includes -Ift_printf/libft/includes
RM = rm -rf

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_MAKE = $(MAKE) -C $(FT_PRINTF_DIR)

LIBFT_DIR = ft_printf/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

SRC_PATH = ./sources
OBJ_PATH = ./build
SRC = $(shell find $(SRC_PATH) -name '*.c')
OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(subst $(SRC_PATH)/,,$(SRC)))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

# bonus: all

$(LIBFT_LIB):
	$(LIBFT_MAKE)

$(FT_PRINTF_LIB):
	$(FT_PRINTF_MAKE)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)


clean:
	$(RM) $(OBJ_PATH)
	$(FT_PRINTF_MAKE) clean
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(FT_PRINTF_MAKE) fclean
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re