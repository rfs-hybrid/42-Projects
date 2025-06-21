NAME = push_swap
PUSH_SWAP_LIB = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes
RM = rm -rf
AR = ar rcs

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = make -C $(LIBFT_DIR)

SRC_PATH = ./srcs
OBJ_PATH = ./objs
SRC = $(shell find $(SRC_PATH) -name '*.c')
OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(subst $(SRC_PATH)/,,$(SRC)))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	$(LIBFT_MAKE)

$(NAME): $(PUSH_SWAP_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(PUSH_SWAP_LIB) $(LIBFT_LIB) -o $(NAME)

$(PUSH_SWAP_LIB): $(OBJ)
	$(AR) $(PUSH_SWAP_LIB) $(OBJ)

bonus:
	$(MAKE) -C bonus

clean:
	$(RM) $(OBJ_PATH)
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(PUSH_SWAP_LIB)
	$(LIBFT_MAKE) fclean
	cd bonus && $(MAKE) fclean

re: fclean all

.PHONY: all bonus clean fclean re