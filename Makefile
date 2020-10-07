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

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_OPRINTF = ./src/
PATH_SPRINTF = ./src/
PATH_IPRINTF = ./src/
PATH_OLIBFT = ./libft/
PATH_SLIBFT = ./libft/
PATH_ILIBFT = ./libft/
FILESLIBFT = ft_strlen ft_putchar ft_putchar_fd ft_putstr ft_putstr_fd ft_putnchar ft_isdigit ft_strchr ft_isspace \
			ft_atoi ft_putnbr ft_putnbr_fd
FILESPRINTF = ft_printf ft_flags ft_conversion ft_putc ft_puts

SLIBFT = $(addprefix $(PATH_SLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OLIBFT = $(addprefix $(PATH_OLIBFT), $(addsuffix .o, $(FILESLIBFT:.c=.o)))
ILIBFT = $(addprefix $(PATH_ILIBFT), libft.h)
SPRINTF = $(addprefix $(PATH_SPRINTF), $(addsuffix .c, $(FILESPRINTF)))
OPRINTF = $(addprefix $(PATH_OPRINTF), $(addsuffix .o, $(FILESPRINTF:.c=.o)))
IPRINTF = $(addprefix $(PATH_IPRINTF), ft_printf.h)

all : $(NAME)

$(NAME) : $(OLIBFT) $(OPRINTF)
	ar rcs $(NAME) $(OPRINTF) $(OLIBFT)

$(PATH_OLIBFT)%.o : $(PATH_SLIBFT)%.c $(ILIBFT)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_ILIBFT)

$(PATH_OPRINTF)%.o : $(PATH_SPRINTF)%.c $(IPRINTF)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_IPRINTF)

clean:	
			@rm -f $(OLIBFT) $(OPRINTF)
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

test:	test.c	libftprintf.a 
		${CC} ${HEADER} -O test.c -o test  -L. -lftprintf 

