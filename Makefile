# Sample Makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
NAME = libftprintf.a

INCLUDE_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRC_FILES =  $(SRC_DIR)/apply_c.c \
			 $(SRC_DIR)/apply_i_d.c \
			 $(SRC_DIR)/apply_p.c \
			 $(SRC_DIR)/apply_s.c \
			 $(SRC_DIR)/apply_u.c \
			 $(SRC_DIR)/apply_x.c \
			 $(SRC_DIR)/ft_printf.c \
			 $(SRC_DIR)/ft_printf_utils.c \
			 $(SRC_DIR)/ft_printf_utils2.c \
			 $(SRC_DIR)/ft_printf_utils3.c \
			 $(SRC_DIR)/ft_printf_utils4.c \
			 $(SRC_DIR)/ft_printf_utils5.c \
			 $(SRC_DIR)/apply_i_d_edge.c \

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

bonus: all

$(NAME): $(OBJ_FILES)
	ar -rcs $@ $(OBJ_FILES)

# Make sure dir exists
$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@if [ -d "$(OBJ_DIR)" ]; then 		rm -rf $(OBJ_DIR); 	fi

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

