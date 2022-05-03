NAME = fdf

SRC = fdf.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

H = fdf.h

all: $(NAME)

$(NAME):  $(H)
	$(CC) $(FLAGS) $(SRC) -o fdf

lean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

n:
	norminette
