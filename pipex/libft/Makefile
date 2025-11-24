# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 15:08:44 by maaugust          #+#    #+#              #
#    Updated: 2025/11/24 15:17:04 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
NAME = libft.a

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf
AR = ar rcs

# =================================== LIBFT ================================== #
LIBFT_SRC_PATH = ./srcs
LIBFT_OBJ_PATH = ./objs
LIBFT_SRC = $(shell find $(LIBFT_SRC_PATH) -name '*.c')
LIBFT_OBJ = $(patsubst %.c, $(LIBFT_OBJ_PATH)/%.o, \
					$(subst $(LIBFT_SRC_PATH)/,,$(LIBFT_SRC)))

# ============================== COMPILER RULES ============================== #
$(LIBFT_OBJ_PATH)/%.o: $(LIBFT_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(NAME)

$(NAME): $(LIBFT_OBJ)
	$(AR) $(NAME) $(LIBFT_OBJ)

# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(LIBFT_OBJ) $(LIBFT_OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all clean fclean re
