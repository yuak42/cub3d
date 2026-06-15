# VARIABLES
NAME = cub3d

LIBFT = libft/libft.a

SRC_DIR = src
SRC_FILES = \
	main.c

# to be deleted
include byaprak.mk
SRC_FILES += $(BYAPRAK_SRC)

include yuak.mk
SRC_FILES += $(YUAK_SRC)
#########

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = $(LIBFT) -Iinclude
##############################################

# RULES

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re

