NAME := push_swap

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

SRCS := \
	main.c \
	algo/sort1.c \
	algo/sort2.c \
	algo/sort3.c \
	checks/checks.c \
	checks/checks2.c \
	libft/ft_atoi.c \
	libft/ft_split.c \
	libft/ft_split2.c \
	operations/op_a.c \
	operations/op_b.c \
	operations/ops.c \
	stacks/create_stack.c \
	stacks/min_max.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC := cc
CFLAGS := -Werror -Wall -Wextra -I$(INC_DIR)

RM := rm -rf
DIR_DUP = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all