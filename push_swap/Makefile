NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
AR = ar rcs

FILES = main.c stack_init.c stack_utils.c stack_utils2.c \
		string_to_stack.c args_to_stack.c validation.c \
		stack_init_utils.c swap_commands.c push_commands.c \
		rotation_commands.c reverse_rotation_commands.c \
		push_swap.c lis_sequence.c lis_algorithm.c algorithm.c algorithm_utils.c

SRC_PATH = ./srcs

OBJ_PATH = ./objs

INC_PATH = ./includes
LIBFT_PATH = ./ft_printf/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF_PATH = ./ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

SRC = $(addprefix $(SRC_PATH)/, $(FILES))

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all: $(LIBFT) $(LIBFTPRINTF) $(OBJ_PATH) $(NAME)

# bonus: all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(INC_PATH) -L$(LIBFTPRINTF_PATH) -L$(LIBFT_PATH) \
		$(OBJ) -lftprintf -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ) $(OBJ_PATH)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re