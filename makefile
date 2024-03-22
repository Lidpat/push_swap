# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 19:54:20 by lpalacio          #+#    #+#              #
#    Updated: 2023/12/09 21:20:16 by lpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c push_swap_utils.c moves_push_swap.c radix_sort.c \
data_precheck_and_load.c

OBJDIR = bin
OBJS	= ${SRCS:%.c=$(OBJDIR)/%.o}

NAME = push_swap
LIBDIR = libft/
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIBFT = -L ${LIBDIR} -lft
LIBFT = libft.a

bin/%.o : %.c
		@mkdir -p ${OBJDIR}
		$(CC) ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} | ${LIBFT}
	$(CC) -o ${NAME} ${OBJS} ${CLIBFT} ${CFLAGS} 
	@echo "push_swap has been compiled"

all: ${NAME}

${LIBFT}:
	$(MAKE) -C $(LIBDIR)


clean: 
	${RM} ${OBJS} $(OBJDIR)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
