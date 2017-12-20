# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2017/12/20 18:55:38 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

#directories

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

# src / obj files

FILES =	main.c \
		draw_tools.c \
		draw.c \
		parser.c \
		bind.c \
		process_coords.c \
		utl.c

SRC =	$(addprefix $(SRC_DIR)/, $(FILES)))
OBJ = 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))


# compiler and flags
CC =		gcc
FLAGS =		-Wall -Werror -Wextra

# frameworks
FRM =		-framework AppKit -framework OpenGL

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/fdf.h ./libft/includes/libft.h
	$(CC) $(FLAGS) -o $@ -I./includes -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(FRM)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf *.dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all
