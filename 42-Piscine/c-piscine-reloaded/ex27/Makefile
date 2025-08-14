NAME = ft_display_file
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_display_file.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
