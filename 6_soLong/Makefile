NAME := so_long

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

SRCS := \
    main.c \
    checking/check_map.c \
    get_next_line/get_next_line_utils.c \
    get_next_line/get_next_line.c

SRC_FILES := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

RM := rm -rf

.PHONY: all clean fclean re

all: $(NAME)
	@echo "==== Full build complete ===="

$(NAME): $(OBJS)
	@echo "==== Linking object files ===="
	@echo "Object files to link: $(OBJS)"
	$(CC) $(OBJS) -o $(NAME)
	@echo "==== Executable created: $(NAME) ===="

# Verbose rule for object file compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "==== Compiling object file: $@ ===="
	@echo "Source file: $<"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "==== Compilation of $@ complete ===="

# Additional debugging targets
print-%:
	@echo '$*=$($*)'

list-files:
	@for file in $(SRCS); do \
		echo "Checking $$file:"; \
		ls -l $(SRC_DIR)/$$file; \
	done

# Clean and rebuild utilities
clean:
	@echo "Removing object files"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Removing executable"
	@$(RM) $(NAME)

re: fclean all