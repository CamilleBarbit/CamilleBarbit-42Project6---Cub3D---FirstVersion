# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:23:44 by camillebarb       #+#    #+#              #
#    Updated: 2022/07/14 17:12:31 by camillebarb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

cc = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

C_FILES = cub3D.c \
			error.c \
			parsing/validity_argv1.c


O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES}
	@${CC} ${O_FILES} -g3 -fsanitize=address -o ${NAME} 

clean: 
	@${RM} ${O_FILES}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re