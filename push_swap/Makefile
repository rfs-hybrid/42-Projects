# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 18:04:18 by maaugust          #+#    #+#              #
#    Updated: 2025/06/21 18:29:35 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======================== PROJECT FILE NAMES ================================ #
PUSH_SWAP = push_swap
PUSH_SWAP_LIB = push_swap.a
CHECKER = checker

# ========================== COMPILER FLAGS ================================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes -Ibonus/includes
RM = rm -rf
AR = ar rcs

# =============================== LIBFT ====================================== #
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = make -C $(LIBFT_DIR)

# ============================= PUSH SWAP ==================================== #
PUSH_SWAP_SRC_PATH = ./srcs
PUSH_SWAP_OBJ_PATH = ./objs
PUSH_SWAP_SRC = $(shell find $(PUSH_SWAP_SRC_PATH) -name '*.c')
PUSH_SWAP_OBJ = $(patsubst %.c, $(PUSH_SWAP_OBJ_PATH)/%.o, \
					$(subst $(PUSH_SWAP_SRC_PATH)/,,$(PUSH_SWAP_SRC)))

# ============================== CHECKER ===================================== #
CHECKER_SRC_PATH = ./bonus/srcs
CHECKER_OBJ_PATH = ./bonus/objs
CHECKER_SRC	  = $(shell find $(CHECKER_SRC_PATH) -name '*.c')
CHECKER_OBJ	  = $(patsubst %.c, $(CHECKER_OBJ_PATH)/%.o, \
					$(subst $(CHECKER_SRC_PATH)/,,$(CHECKER_SRC)))

# ========================== COMPILER RULES ================================== #
$(PUSH_SWAP_OBJ_PATH)/%.o: $(PUSH_SWAP_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ_PATH)/%.o: $(CHECKER_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================== BUILD TARGETS ================================== #
all: $(LIBFT_LIB) $(PUSH_SWAP)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT_LIB) -o $(PUSH_SWAP)

bonus: $(PUSH_SWAP_LIB) $(CHECKER)

$(CHECKER): $(CHECKER_OBJ) $(PUSH_SWAP_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(PUSH_SWAP_LIB) $(LIBFT_LIB) -o $(CHECKER)
	
$(PUSH_SWAP_LIB): $(PUSH_SWAP_OBJ)
	$(AR) $(PUSH_SWAP_LIB) $(PUSH_SWAP_OBJ)

$(LIBFT_LIB):
	$(LIBFT_MAKE)
	
# =========================== CLEAN TARGETS ================================== #
clean:
	$(RM) $(PUSH_SWAP_OBJ_PATH) $(CHECKER_OBJ_PATH)
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(PUSH_SWAP) $(PUSH_SWAP_LIB) $(CHECKER)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all bonus clean fclean re