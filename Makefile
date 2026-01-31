NAME        := push_swap

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCLUDES    := -I include

# Opcional para debug local (actívalo cuando quieras)
# CFLAGS     += -g3

SRC_DIR     := src
OBJ_DIR     := obj

SRCS        := \
$(SRC_DIR)/stack/stack_create.c \
$(SRC_DIR)/stack/stack_add.c \
$(SRC_DIR)/stack/stack_pop.c \
$(SRC_DIR)/instructions/instructions_swap.c \
$(SRC_DIR)/instructions/instructions_push.c \
$(SRC_DIR)/instructions/instructions_rotate.c \
$(SRC_DIR)/instructions/instructions_reverse_rotate.c \
$(SRC_DIR)/parsing/validate_number.c \
$(SRC_DIR)/parsing/check_duplicates.c \
$(SRC_DIR)/parsing/safe_atoi.c \
$(SRC_DIR)/parsing/error.c \
$(SRC_DIR)/parsing/parse_arguments.c \
$(SRC_DIR)/parsing/indexing.c \
$(SRC_DIR)/sorting/sort_small.c \
$(SRC_DIR)/sorting/chunk_sort.c \
$(SRC_DIR)/utils/free_stack.c \
$(SRC_DIR)/push_swap.c\
$(SRC_DIR)/main.c\

# Convertimos src/.../x.c -> obj/.../x.o (mantiene subcarpetas)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Dependencias de headers generadas por el compilador
DEPS        := $(OBJS:.o=.d)

# Flags para generar .d automáticamente
CFLAGS      += -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Regla de compilación: crea carpeta destino y compila
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test test_bin

-include $(DEPS)
