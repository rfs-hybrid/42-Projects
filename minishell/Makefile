# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 18:04:18 by maaugust          #+#    #+#              #
#    Updated: 2025/11/07 16:24:25 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
MINISHELL = minishell

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes
RM = rm -rf
AR = ar rcs

# =================================== LIBFT ================================== #
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = make -C $(LIBFT_DIR)

# ================================= MINISHELL ================================ #
MINISHELL_SRC_PATH = ./srcs
MINISHELL_OBJ_PATH = ./objs
MINISHELL_SRC = $(shell find $(MINISHELL_SRC_PATH) -name '*.c')
MINISHELL_OBJ = $(patsubst %.c, $(MINISHELL_OBJ_PATH)/%.o, \
					$(subst $(MINISHELL_SRC_PATH)/,,$(MINISHELL_SRC)))

# ============================== COMPILER RULES ============================== #
$(MINISHELL_OBJ_PATH)/%.o: $(MINISHELL_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(LIBFT_LIB) $(MINISHELL)

$(MINISHELL): $(MINISHELL_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(MINISHELL_OBJ) $(LIBFT_LIB) -lreadline -o $(MINISHELL)

bonus: all

$(LIBFT_LIB):
	$(LIBFT_MAKE)
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(MINISHELL_OBJ_PATH)
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(MINISHELL)
	$(LIBFT_MAKE) fclean

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all bonus clean fclean re