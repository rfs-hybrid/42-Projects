# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 03:42:32 by maaugust          #+#    #+#              #
#    Updated: 2025/11/24 22:15:53 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
PIPEX = pipex
BONUS = pipex_bonus

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes
RM = rm -rf
AR = ar rcs

# =================================== LIBFT ================================== #
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = make -C $(LIBFT_DIR)

# =================================== PIPEX ================================== #
PIPEX_SRC_PATH = ./mandatory
PIPEX_OBJ_PATH = ./objs/mandatory
PIPEX_SRC = $(shell find $(PIPEX_SRC_PATH) -name '*.c')
PIPEX_OBJ = $(patsubst %.c, $(PIPEX_OBJ_PATH)/%.o, \
					$(subst $(PIPEX_SRC_PATH)/,,$(PIPEX_SRC)))

# =================================== BONUS ================================== #
BONUS_SRC_PATH = ./bonus
BONUS_OBJ_PATH = ./objs/bonus
BONUS_SRC = $(shell find $(BONUS_SRC_PATH) -name '*.c')
BONUS_OBJ = $(patsubst %.c, $(BONUS_OBJ_PATH)/%.o, \
					$(subst $(BONUS_SRC_PATH)/,,$(BONUS_SRC)))

# ============================== COMPILER RULES ============================== #
$(PIPEX_OBJ_PATH)/%.o: $(PIPEX_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_PATH)/%.o: $(BONUS_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(LIBFT_LIB) $(PIPEX)

$(PIPEX): $(PIPEX_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(PIPEX_OBJ) $(LIBFT_LIB) -o $(PIPEX)

bonus: $(LIBFT_LIB) $(BONUS)

$(BONUS): $(BONUS_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_LIB) -o $(BONUS)

$(LIBFT_LIB):
	$(LIBFT_MAKE)
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(PIPEX_OBJ_PATH) $(BONUS_OBJ_PATH)
	rmdir -p --ignore-fail-on-non-empty objs 2>/dev/null || true
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(PIPEX) $(BONUS)
	$(LIBFT_MAKE) fclean

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all bonus clean fclean re
