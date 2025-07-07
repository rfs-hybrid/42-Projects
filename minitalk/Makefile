# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 15:19:49 by maaugust          #+#    #+#              #
#    Updated: 2025/07/07 20:36:38 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
CLIENT = client
SERVER = server

# ============================== COMPILER FLAGS ============================== #
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

# ================================= MINITALK ================================= #
MINITALK_SRC_PATH = ./srcs
MINITALK_OBJ_PATH = ./objs
MINITALK_SRC = $(shell find $(MINITALK_SRC_PATH) -name '*.c')
MINITALK_OBJ = $(patsubst %.c, $(MINITALK_OBJ_PATH)/%.o, \
			$(subst $(MINITALK_SRC_PATH)/,,$(MINITALK_SRC)))
CLIENT_OBJ = $(filter %client.o,$(MINITALK_OBJ))
SERVER_OBJ = $(filter %server.o,$(MINITALK_OBJ))

# ============================== COMPILER RULES ============================== #
$(MINITALK_OBJ_PATH)/%.o: $(MINITALK_SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER)

bonus: all
	
# =============================== CLEAN TARGETS ============================== #
clean:
	$(RM) $(MINITALK_OBJ_PATH)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all bonus clean fclean re