# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 01:07:17 by maaugust          #+#    #+#              #
#    Updated: 2025/09/18 00:26:27 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
PHILO = philo

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf
AR = ar rcs

# =================================== PHILO ================================== #
PHILO_SRC_PATH = ./srcs
PHILO_OBJ_PATH = ./objs
PHILO_SRC = $(shell find $(PHILO_SRC_PATH) -name '*.c')
PHILO_OBJ = $(patsubst %.c, $(PHILO_OBJ_PATH)/%.o, \
					$(subst $(PHILO_SRC_PATH)/,,$(PHILO_SRC)))

# ============================== COMPILER RULES ============================== #
$(PHILO_OBJ_PATH)/%.o: $(PHILO_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(PHILO)

$(PHILO): $(PHILO_OBJ)
	$(CC) $(CFLAGS) $(PHILO_OBJ) -o $(PHILO)

bonus: all
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(PHILO_OBJ_PATH)

fclean: clean
	$(RM) $(PHILO)

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all bonus clean fclean re
