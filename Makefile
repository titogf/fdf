NAME = fdf

SRC = fdf.c keyboard.c keyboard_utils.c color.c map.c bresenham.c  draw.c utils.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Imlx

MINILIBX = minilibx/libmlx.a
MINIFLG = -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo Generating enforcible...
	@make -C minilibx
	$(CC) $(FLAGS) $(OBJS) $(MINILIBX) $(MINIFLG) -o $(NAME)
	@echo $(NAME) Generated!

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C minilibx
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

n:
	norminette $(SRC)
