# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:23:44 by camillebarb       #+#    #+#              #
#    Updated: 2022/07/22 11:15:46 by camillebarb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################

################################ ARGUMENTS #####################################

NAME = cub3D

cc = gcc

RM = rm -rf

CFLAGS = -g -Wall -Wextra -Werror

################################################################################

################################### SOURCES ####################################

C_FILES = cub3D \
			errors_and_exit/error \
			errors_and_exit/exit \
			parsing/validity_argv1 \
			parsing/first_extract \
			parsing/parsing_textures_and_colors \
			utils


O_FILES = $(addsuffix .o, $(C_FILES))

################################################################################

################################### RULES ######################################

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