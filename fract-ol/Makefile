# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 18:04:18 by maaugust          #+#    #+#              #
#    Updated: 2025/07/02 21:23:34 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
FRACTOL = fractol

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes -Iminilibx
RM = rm -rf
AR = ar rcs

# =================================== LIBFT ================================== #
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = make -C $(LIBFT_DIR)

# ================================== MINILIBX ================================ #
MINILIBX_DIR = minilibx
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

$(MINILIBX_LIB):
	$(MINILIBX_MAKE)
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(FRACTOL_OBJ_PATH)
	$(LIBFT_MAKE) clean
	$(MINILIBX_MAKE) clean

fclean: clean
	$(RM) $(FRACTOL)
	$(LIBFT_MAKE) fclean

# ============================== REBUILD TARGETS ============================= #
re: fclean all

# ========================= HEADER DEPENDENCY INCLUDE ======================== #
-include $(FRACTOL_OBJ:.o=.d)

.PHONY: all bonus clean fclean re