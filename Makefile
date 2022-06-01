NAME = fdf

SRC = fdf.c close_map.c read_map.c utils.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Imlx -g3 -fsanitize=address

MINILIBX = minilibx/libmlx.a
MINIFLG = -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx
	$(CC) $(FLAGS) $(OBJS) $(MINILIBX) $(MINIFLG) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C minilibx
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

n:
	norminette $(SRC)
