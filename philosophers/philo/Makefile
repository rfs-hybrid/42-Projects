# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 01:07:17 by maaugust          #+#    #+#              #
#    Updated: 2025/12/25 14:56:17 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
PHILO             = philo

# ============================== COMPILER FLAGS ============================== #
CC                = cc
CFLAGS            = -Wall -Wextra -Werror -pthread
INCLUDES          = -Iincludes -Ilibft/includes
RM                = rm -rf

# ================================== COLORS ================================== #
GREEN             := \033[32m
RED               := \033[31m
YELLOW            := \033[33m
CYAN              := \033[36m
RESET             := \033[0m
BOLD              := \033[1m

# =============================== SOURCE FILES =============================== #
PHILO_SRC_PATH    = ./srcs
PHILO_SRC         = $(shell find $(PHILO_SRC_PATH) -name '*.c')

PHILO_OBJ_PATH    = ./objs
PHILO_OBJ         = $(patsubst $(PHILO_SRC_PATH)/%.c, \
                          $(PHILO_OBJ_PATH)/%.o, $(PHILO_SRC))

# ============================ COMPILATION RULES ============================= #
$(PHILO_OBJ_PATH)/%.o: $(PHILO_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(PHILO)

$(PHILO): $(LIBFT_LIB) $(PHILO_OBJ)
	@printf "$(GREEN)✔ Mandatory objects built successfully.$(RESET)\n"
	@$(CC) $(CFLAGS) $(PHILO_OBJ) -o $(PHILO)
	@printf "$(GREEN)$(BOLD)✔ Build complete → $(PHILO)$(RESET)\n"
	
# ============================== CLEAN TARGETS =============================== #
clean:
	@$(RM) $(PHILO_OBJ_PATH)
	@rmdir -p --ignore-fail-on-non-empty objs 2>/dev/null || true
	@printf "$(YELLOW)• Cleaned object files.$(RESET)\n"

fclean: clean
	@$(RM) $(PHILO)
	@printf "$(RED)• Full clean complete.$(RESET)\n"

re: fclean all

# ================================= VALGRIND ================================= #
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all -s ./PHILO

# ============================== PHONY TARGETS =============================== #
.PHONY: all clean fclean re valgrind
