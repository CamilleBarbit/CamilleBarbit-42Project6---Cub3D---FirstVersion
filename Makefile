# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:23:44 by camillebarb       #+#    #+#              #
#    Updated: 2022/07/20 16:44:18 by camillebarb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

cc = gcc

RM = rm -rf

CFLAGS = -g -Wall -Wextra -Werror

C_FILES = cub3D.c \
			errors_and_exit/error.c \
			errors_and_exit/exit.c \
			parsing/validity_argv1.c \
			parsing/first_extract.c \
			parsing/parsing_textures_and_colors.c \
			utils.c


O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES}
	@${MAKE} -C libft
	@${CC} ${O_FILES} libft/libft.a -o ${NAME} 


clean: 
	@${RM} ${O_FILES}

fclean: clean
	@make fclean -C libft
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re