NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes
RM = rm -rf

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

SRC_PATH = ./srcs
OBJ_PATH = ./objs
SRC = $(shell find $(SRC_PATH) -name '*.c')
OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(subst $(SRC_PATH)/,,$(SRC)))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_LIB) $(NAME)

# bonus: all

$(LIBFT_LIB):
	$(LIBFT_MAKE)

$(FT_PRINTF_LIB):
	$(FT_PRINTF_MAKE)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

clean:
	$(RM) $(OBJ_PATH)
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re