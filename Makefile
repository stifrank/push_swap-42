NAME        := push_swap
BONUS_NAME  := checker

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCLUDES    := -I include -I bonus/get_next_line-42

SRC_DIR     := src
OBJ_DIR     := obj
BONUS_DIR   := bonus
BONUS_OBJ_DIR := obj_bonus

# Flags para generar .d automáticamente
CFLAGS      += -MMD -MP

# -----------------------
# FUENTES COMUNES
# -----------------------
COMMON_SRCS := \
$(SRC_DIR)/stack/stack_create.c \
$(SRC_DIR)/stack/stack_add.c \
$(SRC_DIR)/stack/stack_pop.c \
$(SRC_DIR)/stack/free_stack.c \
$(SRC_DIR)/instructions/instructions_swap.c \
$(SRC_DIR)/instructions/instructions_push.c \
$(SRC_DIR)/instructions/instructions_rotate.c \
$(SRC_DIR)/instructions/instructions_reverse_rotate.c \
$(SRC_DIR)/parsing/validate_number.c \
$(SRC_DIR)/parsing/check_duplicates.c \
$(SRC_DIR)/parsing/safe_atoi.c \
$(SRC_DIR)/parsing/error.c \
$(SRC_DIR)/parsing/parse_arguments.c \
$(SRC_DIR)/sorting/indexing.c \
$(SRC_DIR)/parsing/ps_split_spaces.c \

# -----------------------
# SOLO push_swap
# -----------------------
PS_SRCS := \
$(COMMON_SRCS) \
$(SRC_DIR)/sorting/sort_small.c \
$(SRC_DIR)/sorting/chunk_sort.c \
$(SRC_DIR)/sorting/dispatcher.c \
$(SRC_DIR)/main.c \

# -----------------------
# SOLO bonus (checker)
# -----------------------
BONUS_SRCS := \
$(BONUS_DIR)/main_checker.c \
$(BONUS_DIR)/checker_read.c \
$(BONUS_DIR)/checker_dispatch.c \
$(BONUS_DIR)/checker_utils.c

GNL_SRCS := \
$(BONUS_DIR)/get_next_line-42/get_next_line.c \
$(BONUS_DIR)/get_next_line-42/get_next_line_utils.c

# -----------------------
# OBJETOS
# -----------------------
PS_OBJS := $(PS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
COMMON_OBJS := $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS := $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o) \
              $(GNL_SRCS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

# Dependencias
PS_DEPS := $(PS_OBJS:.o=.d)
BONUS_DEPS := $(BONUS_OBJS:.o=.d)

all: $(NAME)

$(NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(PS_OBJS) -o $@

# Compila src -> obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------
# BONUS
# -----------------------
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(COMMON_OBJS) $(BONUS_OBJS) -o $@

# Compila bonus -> obj_bonus
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(PS_DEPS)
-include $(BONUS_DEPS)