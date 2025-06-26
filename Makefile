NAME	:= cub3d
CC		:= gcc 
INCLUDE	:= ./library
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./library/libft
LIBFT	= library/libft
MINILIBX = library/minilibx
FLAGS	= -Wall -Wextra -Werror
LIBS	= -L$(LIBFT) -lft -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit

SRCDIR	:= source
SRC		:= source/main.c \
			source/checker/checker_utils.c \
			source/checker/file_checker.c \
			source/checker/file_name.c \
			source/checker/map_checker.c \
			source/minilibx/create.c \
			source/minilibx/events.c \
			source/minilibx/image.c \
			source/minilibx/minilibx.c \
			source/minilibx/move_rotate.c \
			source/minilibx/ray_casting.c \
			source/minilibx/ray_utils.c \
			source/minilibx/ray_utils2.c \
			source/minilibx/fov.c \
			source/parser/floor_ceiling.c \
			source/parser/map.c \
			source/parser/parser_utils.c \
			source/parser/parser.c \
			source/utils/color.c \
			source/utils/error.c \
			source/utils/file_exist.c \
			source/utils/free.c \
			source/utils/reader.c \
			source/utils/string.c

OBJDIR	:= ./library/objects
OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(MINILIBX)
	cp $(LIBFT)/libft.a library/.
	cp $(MINILIBX)/libmlx.a library/.
	@$(CC) $(FLAGS) $(CFLAGS) $(OBJ) $(LIBS) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	make clean -C $(MINILIBX)
	rm -rf library/libft.a
	rm -rf library/libmlx.a
	@rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBFT)
	make clean -C $(MINILIBX)
	rm -rf library/libft.a
	rm -rf library/libmlx.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

norm:
	norminette libft

re:	fclean all