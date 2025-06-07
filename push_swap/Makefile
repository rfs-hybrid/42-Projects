NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

FILES = main.c stack_init.c validation.c string_to_stack.c \
		args_to_stack.c stack_utils.c push_swap_utils.c  \
		swap_commands.c push_commands.c rotation_commands.c \
		reverse_rotation_commands.c short_stack_algorithm.c \
		push_swap.c

SRC_PATH = ./srcs

OBJ_PATH = ./objs

INC_PATH = ./includes
LIBFTPRINTF_PATH = ./ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

SRC = $(addprefix $(SRC_PATH)/, $(FILES))

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all: $(LIBFTPRINTF) $(OBJ_PATH) $(NAME)

# bonus: all

$(NAME): $(OBJ)
	cp $(LIBFTPRINTF) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	$(RM) $(OBJ) $(OBJ_PATH)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re