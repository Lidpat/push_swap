# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 19:54:20 by lpalacio          #+#    #+#              #
#    Updated: 2023/11/15 21:59:31 by lpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c

NAME = push_swap
LIBDIR = libft/
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIBFT = -L ${LIBDIR} -lft
LIBFT = libft.a



${NAME}: ${SRCS} | ${LIBFT}
	@$(CC) -o ${NAME} ${SRCS} ${CLIBFT} ${CFLAGS} 

all: ${NAME}

${LIBFT}:
	@cd ${LIBDIR} && $(MAKE)


clean: 
	@${RM} ${NAME}

fclean: clean
	@cd ${LIBDIR} && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
