# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <vtolochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 18:36:10 by vtolochk          #+#    #+#              #
#    Updated: 2018/03/17 15:13:53 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf

HEADER = includes/fdf.h

LIBFT = Libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Iincludes

HEADER_FLAGS = -lmlx -framework OpenGL -framework AppKit

CC = gcc

vpath %.c srcs/

SRCS = divide_and_multiply.c drew_legend.c drew_line.c get_coords.c \
	   img_functions.c initialization.c keys.c main.c move_map.c \
	   rotate_coords.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(HEADER_FLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C Libft/

clean:
	rm -f $(OBJ)
	make clean -C Libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C Libft/

re: fclean all
