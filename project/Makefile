MAKEFLAGS += --silent

NAME = cub3D

SRC_DIR = src
SRC =	main.c \
		renderer/render.c renderer/set_dir.c renderer/set_position.c renderer/utils.c renderer/set_plane.c renderer/set_raydir.c \
		renderer/init_window.c renderer/set_map.c renderer/get_raycast_arg.c renderer/dda_run.c renderer/set_size.c renderer/put_image.c \
		renderer/put_window.c \
		render_utils/close_win.c render_utils/key_event.c render_utils/ray_move.c render_utils/key_utils.c \
		render_utils/move_position.c render_utils/free_render.c \
		parser/init_game.c parser/extract_map.c parser/extract_map_utils.c parser/get_texture_paths.c parser/assign_texture.c \
		parser/texture_utils.c parser/get_player_position.c	\
		check_utils/check_input.c check_utils/print_error.c check_utils/check_identifiers.c check_utils/get_splitted_size.c \
		check_utils/check_colors.c check_utils/is_map_position_true.c check_utils/check_map.c \
		check_utils/get_grid_copy.c check_utils/flood_fill.c check_utils/check_starting_position.c \
		check_utils/is_there_map.c check_utils/is_map_line.c check_utils/print_error_arg.c \
		free_utils/free_split.c free_utils/free_game.c free_utils/free_map.c free_utils/free_texture.c free_utils/free_grid.c \
		print_functions/print_map.c print_functions/print_texture_paths.c check_utils/check_invalid_line.c \
		print_functions/print_player_info.c \
		read_next_line/buffer_utils.c read_next_line/line_utils.c read_next_line/read_next_line.c read_next_line/utils.c

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT = libft/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

CFLAGS = -Wall -Wextra -Werror -Iinclude
DEBUG_FLAGS = -fsanitize=address -g3

LIBS = $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC = cc

FCLEAN_FILES_FOR_MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C libft
	echo "make -C libft"

$(MLX): $(MLX_DIR)
	make -C $(MLX_DIR)
	echo "make -C mlx"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c  $< -o $@


$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO); \
	fi

clean:
	rm -rf $(MLX_DIR)/obj
	make -C libft clean
	rm -rf $(OBJ_DIR)
	echo "make clean"

fclean: clean
	rm -f $(FCLEAN_FILES_FOR_MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)
	echo "make fclean"

re:
	make fclean
	make

debug:
	make fclean
	make $(MLX)
	make all CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"
	echo "make debug"

.PHONY: all clean fclean re
