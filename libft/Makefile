# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 15:53:27 by cbarbit           #+#    #+#              #
#    Updated: 2021/12/01 13:17:21 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = libft.a
CC = gcc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \

C_SRCSFILES = $(addsuffix .c, $(SRCS))
O_SRCSFILES = $(addsuffix .o, $(SRCS))

BONUS = ft_lstadd_front \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstsize \
		ft_lstnew \
		ft_lstlast \
		ft_lstiter \
		ft_lstmap \

C_BONUSFILES = $(addsuffix .c, $(BONUS))
O_BONUSFILES = $(addsuffix .o, $(BONUS))

HDRS = libft.h

${EXEC}: ${O_SRCSFILES}
	${AR} ${EXEC} ${O_SRCSFILES}

.c.o:
	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

all: ${EXEC}

bonus: ${O_BONUSFILES} ${O_SRCSFILES}
	${AR} ${EXEC} ${O_BONUSFILES} ${O_SRCSFILES} 

clean:
	${RM} ${O_SRCSFILES} ${O_BONUSFILES}

fclean: clean
	${RM} ${EXEC}

re: fclean all

.PHONY: all clean fclean re
