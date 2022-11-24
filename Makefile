# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 22:05:25 by hdrabi            #+#    #+#              #
#    Updated: 2022/04/10 07:20:34 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parsing/parsing_utils_five.c \
		parsing/parsing_utils_four.c \
		parsing/parsing_utils_one.c \
		parsing/parsing_utils_six.c \
		parsing/parsing_utils_three.c \
		parsing/parsing_utils_two.c \
		parsing/parsing_utils_seven.c \
		parsing/main_parse.c \
		utils/utils.c \
		init/init.c \
		init/dda.c \
		graphic/draw_screen.c \
		keypress/key_press.c \
		keypress/key_press2.c \

SRCM = main.c

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRCM) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

run : re
	clear && ./cub3d map.cub