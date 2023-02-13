# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 23:52:54 by mcesar-d          #+#    #+#              #
#    Updated: 2023/02/12 21:28:02 by mcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src/

VPATH = $(SRC_DIR)

SOURCES =	cub3d.c\
			check_file.c\
			check_input.c\
			check_map_two.c\
			check_map.c\
			create_map.c\
			init.c\
			get_header.c\
			test.c\
			utils_print.c\
			utils.c

NAME = cub3D
FLAGS = -g3 #-Werror -Wextra -Wall
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
RM = rm -rf
LIBFT = ./libraries/libft/libft.a
LIBFT_PATH = ./libraries/libft
MLX = ./libraries/minilibx-linux/libmlx.a
MLX_PATH = ./libraries/minilibx-linux

SRC_PATH =	./
OBJ_PATH =	obj/
SRCS =	${addprefix ${SRC_PATH}, ${SOURCES}}
OBJS =	$(addprefix $(OBJ_PATH), $(SOURCES:.c=.o))

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

#$(NAME) : $(MLX) $(LIBFT) $(OBJS)
#	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) -L$(MLX_PATH) $(MLX_FLAGS)

${OBJ_PATH}%.o:	$(SRC_PATH)%.c
				@mkdir -p obj
				@${CC} ${FLAGS} -c $< -o $@

$(MLX):
			make -C $(MLX_PATH)

$(LIBFT):
			make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_PATH)
	make clean -C ${LIBFT_PATH}
	make clean -C ${MLX_PATH}

fclean: clean
	$(RM) $(NAME)
	make fclean -C ${LIBFT_PATH}

re: fclean all

val: all
	valgrind --leak-check=full ./cub3D ./assets/maps/teste.cub

.PHONY: all bonus clean fclean re rebonus mlx
