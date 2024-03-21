# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 19:15:57 by ivanrodr          #+#    #+#              #
#    Updated: 2024/03/21 22:29:21 by ivanrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
MLX_CF		:= -framework OpenGL -framework AppKit
CFLAGS		:= -Wall -Wextra -Werror -Ilib/libft 
MLX_PATH	:= lib/minilibx_opengl
LIBFT_PATH	:= lib/libft
#FT_PRINTF_PATH	:= lib/ft_printf
#INCLUDE 	:= src/so_long.h
SRC 		:= src/main.c

#OBJF = .cache_exists

ifeq ($(shell uname), Linux)
$(NAME): MLX_CF	= -L lib/minilibx-linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_PATH = lib/minilibx-linux
endif

all:$(NAME)

$(NAME): $(SRC) $(INCLUDE)
	mkdir -p bin
	make -C $(LIBFT_PATH) 
	make -C $(MLX_PATH) 2>/dev/null
#	make -C $(FT_PRINTF_PATH)
	mv $(MLX_PATH)/libmlx.a bin/
	mv $(LIBFT_PATH)/libft.a bin/
#	mv $(FT_PRINTF_PATH)/libftprintf.a bin/
	cc  $(CFLAGS) $(MLX_CF) bin/libmlx.a bin/libft.a $(SRC) -o $(NAME) 

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf obj	
	rm -rf bin
fclean: clean
	rm -rf $(NAME)
	
re: clean all 
.PHONY: all clean fclean re