# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <vtolochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 18:36:10 by vtolochk          #+#    #+#              #
#    Updated: 2018/03/16 20:17:18 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf

HEADER = includes/fdf.h

LIBFT_NAME = libft.a

LIBFT_DIR = Libft/

CFLAGS = -Wall -Wextra -Werror -Iincludes

HEADER_FLAGS = -lmlx -framework OpenGL -framework AppKit

CC = gcc

vpath %.c srcs/

SRCS = divide_and_multiply.c drew_legend.c drew_line.c get_coords.c \
	   img_functions.c initialization.c keys.c main.c move_map.c \
	   rotate_coords.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ) 
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(HEADER_FLAGS) $(LIBFT_DIR)$(LIBFT_NAME) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
