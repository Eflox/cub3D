# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charlesdansembourg <marvin@42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 19:27:23 by charlesda         #+#    #+#              #
#    Updated: 2021/05/14 19:46:25 by chde-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= src/ft_memset.c \
				src/ft_bzero.c \
				src/ft_memcpy.c \
				src/ft_memccpy.c \
				src/ft_memmove.c \
				src/ft_memchr.c \
				src/ft_memcmp.c \
				src/ft_strlen.c \
				src/ft_isalpha.c \
				src/ft_isdigit.c \
				src/ft_isalnum.c \
				src/ft_isascii.c \
				src/ft_isinset.c \
				src/ft_isprint.c \
				src/ft_toupper.c \
				src/ft_tolower.c \
				src/ft_strrchr.c \
				src/ft_strncmp.c \
				src/ft_strlcpy.c \
				src/ft_strlcat.c \
				src/ft_atoi.c \
				src/ft_atoi_err_max.c \
				src/ft_substr.c \
				src/ft_strjoin.c \
				src/ft_strjoin_free_first.c \
				src/ft_strjoin_free_all.c \
				src/ft_putchar_fd.c \
				src/ft_putstr_fd.c \
				src/ft_putendl_fd.c \
				src/ft_putnbr_fd.c \
				src/ft_split.c \
				src/ft_strcmp.c \
				src/get_next_line.c \
				src/get_next_line2.c 

SBONUS		= src/ft_lstadd_front.c \
				src/ft_lstadd_back.c \
				src/ft_lstclear.c \
				src/ft_lstdelone.c \
				src/ft_lstiter.c \
				src/ft_lstsize.c \
				src/ft_lstlast.c

SRCSH		= include/libft.h

OBJS		= $(SRCSC:%.c=%.o)

OBONUS		= $(SBONUS:%.c=%.o)

NAME		= libft.a

CC			= gcc

AR			= ar -rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		all ${OBONUS}
			${AR} ${NAME} ${OBJS} ${OBONUS}

.PHONY:		all clean fclean re
