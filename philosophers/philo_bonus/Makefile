# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 01:07:17 by maaugust          #+#    #+#              #
#    Updated: 2025/12/29 17:32:23 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
PHILO_BONUS             = philo_bonus

# ============================== COMPILER FLAGS ============================== #
CC                      = cc
CFLAGS                  = -Wall -Wextra -Werror -pthread
INCLUDES                = -Iincludes
RM                      = rm -rf

# ================================== COLORS ================================== #
GREEN                   := \033[32m
RED                     := \033[31m
YELLOW                  := \033[33m
CYAN                    := \033[36m
RESET                   := \033[0m
BOLD                    := \033[1m

# =============================== SOURCE FILES =============================== #
PHILO_BONUS_SRC_PATH    = ./srcs
PHILO_BONUS_SRC         = $(shell find $(PHILO_BONUS_SRC_PATH) -name '*.c')

PHILO_BONUS_OBJ_PATH    = ./objs
PHILO_BONUS_OBJ         = $(patsubst $(PHILO_BONUS_SRC_PATH)/%.c, \
                          $(PHILO_BONUS_OBJ_PATH)/%.o, $(PHILO_BONUS_SRC))

# ============================ COMPILATION RULES ============================= #
$(PHILO_BONUS_OBJ_PATH)/%.o: $(PHILO_BONUS_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(PHILO_BONUS)

bonus: all

$(PHILO_BONUS): $(PHILO_BONUS_OBJ)
	@printf "$(GREEN)✔ Bonus objects built successfully.$(RESET)\n"
	@$(CC) $(CFLAGS) $(PHILO_BONUS_OBJ) -o $(PHILO_BONUS)
	@printf "$(GREEN)$(BOLD)✔ Build complete → $(PHILO_BONUS)$(RESET)\n"
	
# ============================== CLEAN TARGETS =============================== #
clean:
	@$(RM) $(PHILO_BONUS_OBJ_PATH)
	@rmdir -p --ignore-fail-on-non-empty objs 2>/dev/null || true
	@printf "$(YELLOW)• Cleaned object files.$(RESET)\n"

fclean: clean
	@$(RM) $(PHILO_BONUS)
	@printf "$(RED)• Full clean complete.$(RESET)\n"

re: fclean all

# ================================= VALGRIND ================================= #
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all -s ./PHILO_BONUS

# ============================== PHONY TARGETS =============================== #
.PHONY: all bonus clean fclean re valgrind
