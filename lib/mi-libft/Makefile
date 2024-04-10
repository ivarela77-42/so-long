# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 13:33:50 by ivanrodr          #+#    #+#              #
#    Updated: 2024/03/28 19:41:14 by ivanrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la libreria
NAME            := libft.a

# Carpetas
SRC_DIR         := src
OBJ_DIR         := obj
INC_DIR         := includes
#INC_DIR         := .

# Compilador
CC              := gcc
CFLAGS          := -Wall -Wextra -Werror
INCLUDES        := -I$(INC_DIR)
RM              := rm -rf

# Archivos fuente
SRC_FILES := src/ft_strlen.c src/ft_putstr_fd.c src/ft_strdup.c src/ft_memcpy.c \
			 src/ft_strncmp.c src/get_next_line_utils.c src/get_next_line.c \
			 src/ft_bzero.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_putnbr_fd.c \
			 src/ft_putchar_fd.c src/ft_itoa.c
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
INC_FILES := $(INC_DIR)/libft.h

# Reglas
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re