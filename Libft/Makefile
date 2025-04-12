NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC_PART1 =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRC_PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c
OBJ_PART1 = $(SRC_PART1:%.c=%.o)
OBJ_PART2 = $(SRC_PART2:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_PART1) $(OBJ_PART2)
	$(AR) $(NAME) $(OBJ_PART1) $(OBJ_PART2)

all: $(NAME)

bonus: $(NAME)
	$(CC) $(CFLAGS) -c $(SRC_BONUS)
	$(AR) $(NAME) $(OBJ_PART1) $(OBJ_PART2) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ_PART1) $(OBJ_PART2) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC_PART1) $(SRC_PART2) $(SRC_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ_PART1) $(OBJ_PART2) $(OBJ_BONUS)

.PHONY: all bonus clean fclean re so
