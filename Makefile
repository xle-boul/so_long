# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 09:58:10 by xle-boul          #+#    #+#              #
#    Updated: 2022/03/17 21:30:10 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SOURCES = so_long.c 			\
gnl/get_next_line.c 			\
gnl/get_next_line_utils.c		\
sources/map_init.c				\
sources/free.c					\
sources/map_checkers.c			\
sources/error_handler.c			\
sources/mlx_map_init.c			\
sources/mlx_movements.c

SOURCES_BONUS = so_long.c 			\
gnl/get_next_line.c 				\
gnl/get_next_line_utils.c			\
sources/map_init.c					\
bonus/free_bonus.c					\
bonus/map_checkers_bonus.c			\
bonus/error_handler_bonus.c			\
bonus/mlx_map_init_bonus.c			\
bonus/mlx_movements_bonus.c			\
bonus/mlx_enemy_mvt_init_bonus.c	\
bonus/mlx_enemy_movement_bonus.c	\
bonus/mlx_enemy_textures_bonus.c	\
bonus/mlx_sprite.c					\
bonus/mlx_string_stuff.c			\
bonus/free_base_bonus.c

CC = gcc

OBJ_MLX = mlx_linux/obj/*.o
MLX_DIR = mlx_linux/
OBJ_DIR = objs/
OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(SOURCES_BONUS:.c=.o)
OBJ_DIR_BONUS = objs_bonus/

INCLUDES = includes/
INCLUDES_BONUS = includes/

FLAGS = -Werror -Wall -Wextra
EXTRA_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz

LIB_DIR = ft_printf/
LIB_OBJS_DIR = ft_printf/objs/
LIB = libftprintf.a
LIB_MLX = libmlx_Linux.a

$(NAME): $(LIB) $(LIB_MLX) $(OBJ_DIR)
	@$(CC) $(FLAGS) $(OBJ_MLX) $(EXTRA_FLAGS) $(SOURCES) $(LIB) -I $(INCLUDES) -o $(NAME)
	@echo "Compiling so_long..."
	@printf "\033[0;32mso_long compiled! Run using ./so_long <path_to/map.ber>\n\e[0m"

$(LIB):
	@make bonus $(LIB) -C $(LIB_DIR)
	@mv $(LIB_DIR)$(LIB) .

$(LIB_MLX):
	@make -C $(MLX_DIR)
	@mv $(MLX_DIR)$(LIB_MLX) .

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SOURCES) -c
	@mv *.o $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SOURCES_BONUS) -c
	@mv *.o $(OBJ_DIR_BONUS)
	

all: $(NAME)

clean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIB)
	@rm -f $(LIB_MLX)
	@make -C $(LIB_DIR) fclean
	@make -C $(MLX_DIR) clean

re: fclean $(NAME)

bonus: $(LIB) $(LIB_MLX) $(OBJ_DIR_BONUS)
	@$(CC) $(FLAGS) $(OBJ_MLX) $(EXTRA_FLAGS) $(SOURCES_BONUS) $(LIB) $(LIB_MLX) -I $(INCLUDES_BONUS) -o $(NAME_BONUS)
	@echo "Compiling so_long_bonus..."
	@printf "\033[0;32mso_long_bonus compiled! Run using ./so_long_bonus <path_to/map.ber>\n\e[0m"

bonus_clean:
	@rm -f $(NAME_BONUS)
	@rm -rf $(OBJ_DIR_BONUS)

bonus_fclean: bonus_clean
	@rm -rf $(LIB)
	@rm -f $(LIB_MLX)
	@make -C $(LIB_DIR) fclean
	@make -C $(MLX_DIR) clean
	
bonus_re: bonus_fclean bonus

.PHONY: all clean fclean bonus bonus_re bonus_fclean re