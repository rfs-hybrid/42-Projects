# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 03:42:32 by maaugust          #+#    #+#              #
#    Updated: 2025/11/24 15:09:18 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
PIPEX = pipex

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
PIPEX_SRC_PATH = ./srcs
PIPEX_OBJ_PATH = ./objs
PIPEX_SRC = $(shell find $(PIPEX_SRC_PATH) -name '*.c')
PIPEX_OBJ = $(patsubst %.c, $(PIPEX_OBJ_PATH)/%.o, \
					$(subst $(PIPEX_SRC_PATH)/,,$(PIPEX_SRC)))

# ============================== COMPILER RULES ============================== #
$(PIPEX_OBJ_PATH)/%.o: $(PIPEX_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(LIBFT_LIB) $(PIPEX)

$(PIPEX): $(PIPEX_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(PIPEX_OBJ) $(LIBFT_LIB) -o $(PIPEX)

bonus: all

$(LIBFT_LIB):
	$(LIBFT_MAKE)
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(PIPEX_OBJ_PATH)
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(PIPEX)
	$(LIBFT_MAKE) fclean

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all bonus clean fclean re
