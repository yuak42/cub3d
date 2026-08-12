MAKEFLAGS += --silent
# VARIABLES
NAME = cub3d

SRC_DIR = src
SRC = main.c renderer/render.c parser/init_game.c

# to be deleted
include byaprak.mk
SRC += $(BYAPRAK_SRC)

include yuak.mk
SRC += $(YUAK_SRC)
######################

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT = libft/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

CFLAGS = -Wall -Wextra -Werror -Iinclude
CFLAGS += -fsanitize=address -g3 #To be deleted later


LIBS = $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11

CC = cc

FCLEAN_FILES_FOR_MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a

# RULES
all: $(NAME)


$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C libft
	echo "make -C libft"

$(MLX):
	make -C $(MLX_DIR)
	echo "make -C mlx"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c  $< -o $@

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

re: fclean all

debug:
	make fclean
	make all $(CFLAGS)="$(CFLAGS) + -g"
	echo "make debug"

.PHONY: all clean fclean re
