NAME = cub3d

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

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re

