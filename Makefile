# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 19:15:57 by ivanrodr          #+#    #+#              #
#    Updated: 2024/03/28 16:25:57 by ivanrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
#MLX_CF		:= -framework OpenGL -framework AppKit
CFLAGS		:= -Wall -Wextra -Werror -Ilib/libft 
#MLX_PATH	:= lib/mlx
LIBFT_PATH	:= lib/libft
MLX			:= lib/mlx_linux_linux.a
MLX_CF		:= -framework OpenGL -framework AppKit
MLX_PATH 	:= lib/minilibx_macos
#FT_PRINTF_PATH	:= lib/ft_printf
INCLUDE 	:= includes/so_long.h
SRC 		:= src/main.c src/check_file_errors.c src/check_map_errors.c \
			   src/map_utilities.c src/game_utilities.c src/images_utilities.c \
			   src/game_actions.c

ifeq ($(shell uname), Linux)
$(NAME): MLX_CF	= -L./lib/mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_PATH = ./lib/mlx_linux
endif

all:$(NAME)

$(NAME): $(SRC) $(INCLUDE)
	mkdir -p bin
	make -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/libft.a bin/
	make -C $(MLX_PATH) 2>/dev/null
	mv	$(MLX_PATH)/libmlx.a bin/
#	mv $(LIBFT_PATH)/libft.a bin/
	cc  $(CFLAGS) $(SRC) $(MLX_CF) bin/libmlx.a bin/libft.a -o $(NAME) 

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	rm -rf obj	
	rm -rf bin
fclean: clean
	rm -rf $(NAME)
	
re: clean all 
.PHONY: all clean fclean re