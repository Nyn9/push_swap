# Colors
GREEN=\033[1;32m
RED=\033[0;31m
BLUE=\033[1;34m
PURPLE=\033[1;35m
END=\033[0m

.SILENT:

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include/
RM = rm -rf

LIBFT = libft.a
LIBPATH = lib/
LIB = $(addprefix $(LIBPATH), $(LIBFT))

NAME = push_swap
SRCS = main.c operations.c count.c utils.c sort.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBPATH) --no-print-directory
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	echo "$(PURPLE)Push_swap ready !$(END)"

clean:
	make clean -C $(LIBPATH) --no-print-directory
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH) --no-print-directory
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re