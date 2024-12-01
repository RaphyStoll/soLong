NAME = find_key
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
LFLAGS = -Imlx -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRC = find_key.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
