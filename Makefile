NAME = fdf

SRC = fdf.c keyboard.c keyboard_utils.c pixel.c color.c map.c menu.c bresenham.c rotate.c draw.c utils.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

RED	= '\033[1;31m'
GREEN	= '\033[1;32m'
BLUE	= '\033[1;34m'
WHITE	= '\033[1;37m'

CC = gcc

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Imlx

MINILIBX = minilibx/libmlx.a
MINIFLG = -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN)"Generating enforcible..."$(WHITE)
	@make -C minilibx
	$(CC) $(FLAGS) $(OBJS) $(MINILIBX) $(MINIFLG) -o $(NAME)
	@echo $(GREEN)"$(NAME) Generated!"$(WHITE)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C minilibx
	rm -f $(OBJS)
	@echo $(RED)"OBJS were deleted"$(WHITE)

fclean: clean
	rm -f $(NAME)
	@echo $(RED)"$(NAME) deleted"$(WHITE)

re: fclean all

n:
	"norminette" $(SRC) fdf.h
