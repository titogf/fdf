NAME = fdf

SRC = fdf.c utils.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Imlx

MINILIBX = /minilibx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lmlx framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

n:
	norminette
