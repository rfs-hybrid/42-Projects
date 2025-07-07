# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 18:04:18 by maaugust          #+#    #+#              #
#    Updated: 2025/07/07 16:39:47 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
FRACTOL = fractol

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes -Iminilibx-linux
RM = rm -rf
AR = ar rcs

# =================================== LIBFT ================================== #
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = make -C $(LIBFT_DIR)

# ================================== MINILIBX ================================ #
MINILIBX_URL = https://github.com/42paris/minilibx-linux.git
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_MAKE = make -C $(MINILIBX_DIR)

# ================================= FRACT-OL ================================= #
FRACTOL_SRC_PATH = ./srcs
FRACTOL_OBJ_PATH = ./objs
FRACTOL_SRC = $(shell find $(FRACTOL_SRC_PATH) -name '*.c')
FRACTOL_OBJ = $(patsubst %.c, $(FRACTOL_OBJ_PATH)/%.o, \
					$(subst $(FRACTOL_SRC_PATH)/,,$(FRACTOL_SRC)))

# ============================== COMPILER RULES ============================== #
$(FRACTOL_OBJ_PATH)/%.o: $(FRACTOL_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(LIBFT_LIB) $(MINILIBX_LIB) $(FRACTOL)

$(FRACTOL): $(FRACTOL_OBJ) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(FRACTOL_OBJ) $(LIBFT_LIB) $(MINILIBX_LIB) \
	-lXext -lX11 -lm -lz -o $(FRACTOL)

bonus: all

$(LIBFT_LIB):
	$(LIBFT_MAKE)

$(MINILIBX_DIR):
	test -d $(MINILIBX_DIR) || git clone $(MINILIBX_URL)

$(MINILIBX_LIB): $(MINILIBX_DIR)
	$(MINILIBX_MAKE)
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(FRACTOL_OBJ_PATH)
	$(LIBFT_MAKE) clean
	@if [ -d $(MINILIBX_DIR) ]; then $(MINILIBX_MAKE) clean; fi

fclean: clean
	$(RM) $(FRACTOL) $(MINILIBX_DIR)
	$(LIBFT_MAKE) fclean

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all bonus clean fclean re