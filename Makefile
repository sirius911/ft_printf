# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/04 15:53:15 by clorin            #+#    #+#              #
#    Updated: 2020/10/04 15:53:17 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.phony: all clean fclean re

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I includes/

SRCS		= ft_printf.c \
		src/ft_putchar.c

OBJS		= ${SRCS:.c=.o}

.c.o:
			@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}
			@echo "compilation : "$< "\033[32mok\033[0m"	

all:		${NAME}

$(NAME):	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@echo "\033[0m\nCréation de la librairie ... \033[32mok\033[0m"
			@ranlib ${NAME}
			@echo "Optimisation ... \033[32mok\033[0m"
			@echo "\033[1;31;40m -------------- TERMINÉ ---------------\033[0m"

clean:	
			@rm -f ${OBJS}
			@echo "\n\033[32m"
			@echo " ██████ ██      ███████  █████  ███    ██"
			@echo "██      ██      ██      ██   ██ ████   ██"
			@echo "██      ██      █████   ███████ ██ ██  ██"
			@echo "██      ██      ██      ██   ██ ██  ██ ██"
			@echo " ██████ ███████ ███████ ██   ██ ██   ████"
			@echo "\033[0m\nSuppression fichiers *.o  ... \033[32mok\033[0m"

fclean:		clean
			@rm -f ${NAME}
			@echo "\033[0mSuppression "${NAME}" ... \033[32mok\033[0m"
			@rm -f test
			
re:		fclean	all

test:		libftprintf.a 
		${CC} ${HEADER} -L. -O test.c -o test -lftprintf

