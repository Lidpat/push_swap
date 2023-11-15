SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		  ft_toupper.c ft_tolower.c \
		  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c \
		  ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c

OBJDIR = bin
OBJS	= ${SRCS:%.c=$(OBJDIR)/%.o}
OBJ_BONUS = ${BONUS:%.c=$(OBJDIR)/%.o}
NAME	= libft.a
NAME_BONUS = .bonus
RM	= rm -rf
CC = gcc
CFLAGS	= -Wall -Wextra -Werror

bin/%.o : %.c
		@$(CC) ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
	@ar crus ${NAME} ${OBJS}

$(OBJS): | $(OBJDIR)

all:	${NAME} bonus

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS} 
	@ar crus ${NAME} ${OBJ_BONUS}
	@touch .bonus

$(OBJ_BONUS): | $(OBJDIR)

${OBJDIR}:
	@mkdir ${OBJDIR}

clean: 
		@${RM} ${OBJS} ${OBJ_BONUS} 

fclean:		clean
			@${RM} ${NAME} ${NAME_BONUS} $(OBJDIR)

re:	fclean all

re_bonus: re bonus

.PHONY: all bonus clean fclean re re_bonus
