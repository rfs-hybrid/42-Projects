NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I../includes -I../libft/includes
RM = rm -rf

LIBFT_DIR = ../libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

PUSH_SWAP_DIR = ..
PUSH_SWAP_LIB = ../push_swap.a
PUSH_SWAP_MAKE = $(MAKE) -C ..

SRC_PATH = ./srcs
OBJ_PATH = ./objs
SRC = $(shell find $(SRC_PATH) -name '*.c')
OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(subst $(SRC_PATH)/,,$(SRC)))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: ../$(NAME)

../$(NAME): $(NAME)
	cp $(NAME) ..

$(NAME): $(OBJ) $(PUSH_SWAP_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(PUSH_SWAP_LIB) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(LIBFT_MAKE)

$(PUSH_SWAP_LIB):
	$(PUSH_SWAP_MAKE)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	cd .. && $(RM) $(PUSH_SWAP_LIB)

re: fclean all

.PHONY: all clean fclean re