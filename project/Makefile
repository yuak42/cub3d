MAKEFLAGS += --silent
# VARIABLES
NAME = cub3d

SRC_DIR = src
SRC = main.c

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

CFLAGS = -Wall -Wextra -Werror -Iinclude

LIBS = $(LIBFT)

CC = cc

# RULES
all: $(NAME)
	echo "cub3d"

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft
	echo "make -C libft"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)
	echo "make clean"

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	echo "make fclean"

re: fclean all

.PHONY: all clean fclean re
