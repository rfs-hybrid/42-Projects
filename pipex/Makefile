# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 03:42:32 by maaugust          #+#    #+#              #
#    Updated: 2025/11/26 11:37:28 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
PIPEX      := pipex
BONUS      := pipex_bonus

# ============================== COMPILER FLAGS ============================== #
CC         := cc
CFLAGS     := -Wall -Wextra -Werror -Iincludes -Ilibft/includes
RM         := rm -rf

# ================================== LIBFT =================================== #
LIBFT_DIR  := libft
LIBFT_LIB  := $(LIBFT_DIR)/libft.a

# ================================== COLORS ================================== #
GREEN      := \033[32m
RED        := \033[31m
YELLOW     := \033[33m
CYAN       := \033[36m
RESET      := \033[0m
BOLD       := \033[1m

# =============================== SOURCE FILES =============================== #
PIPEX_SRC_PATH   := ./srcs
BONUS_SRC_PATH   := ./srcs/bonus

PIPEX_SRC        := $(shell find $(PIPEX_SRC_PATH) -maxdepth 1 -name '*.c')
BONUS_SRC        := $(shell find $(BONUS_SRC_PATH) -name '*.c')

PIPEX_OBJ_PATH   := ./objs/mandatory
BONUS_OBJ_PATH   := ./objs/bonus

PIPEX_OBJ        := $(patsubst $(PIPEX_SRC_PATH)/%.c, $(PIPEX_OBJ_PATH)/%.o, $(PIPEX_SRC))
BONUS_OBJ        := $(patsubst $(BONUS_SRC_PATH)/%.c, $(BONUS_OBJ_PATH)/%.o, $(BONUS_SRC))

# ============================ COMPILATION RULES ============================= #
$(PIPEX_OBJ_PATH)/%.o: $(PIPEX_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_PATH)/%.o: $(BONUS_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

# ============================== BUILD TARGETS =============================== #
all: $(PIPEX)

bonus: $(BONUS)

$(PIPEX): $(LIBFT_LIB) $(PIPEX_OBJ)
	@printf "$(GREEN)✔ Mandatory objects built successfully.$(RESET)\n"
	@$(CC) $(CFLAGS) $(PIPEX_OBJ) $(LIBFT_LIB) -o $(PIPEX)
	@printf "$(GREEN)$(BOLD)✔ Build complete → $(PIPEX)$(RESET)\n"

$(BONUS): $(LIBFT_LIB) $(BONUS_OBJ)
	@printf "$(GREEN)✔ Bonus objects built successfully.$(RESET)\n"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_LIB) -o $(BONUS)
	@printf "$(GREEN)$(BOLD)✔ Build complete → $(BONUS)$(RESET)\n"

$(LIBFT_LIB):
	@printf "$(CYAN)→ Building Libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null || { printf "$(RED)✖ Libft build failed!$(RESET)\n"; exit 1; }
	@printf "$(GREEN)✔ Libft built.$(RESET)\n"

# ============================== CLEAN TARGETS =============================== #
clean:
	@$(RM) $(PIPEX_OBJ_PATH) $(BONUS_OBJ_PATH)
	@rmdir -p --ignore-fail-on-non-empty objs 2>/dev/null || true
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null
	@printf "$(YELLOW)• Cleaned object files.$(RESET)\n"

fclean: clean
	@$(RM) $(PIPEX) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null
	@printf "$(RED)• Full clean complete.$(RESET)\n"

re: fclean all

# ============================== PHONY TARGETS =============================== #
.PHONY: all bonus clean fclean re
