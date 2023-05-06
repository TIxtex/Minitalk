# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 19:37:36 by ulherrer          #+#    #+#              #
#    Updated: 2023/05/06 13:10:03 by uliherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tools.a

CC = clang -std=c11
CFLAGS = -Wall -Wextra -Werror -pedantic

INCLUDE = tools.h

SOURCES = \
ft_atoi.c \
ft_strjoin.c \
ft_strlen.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_print_pid.c \
ft_puterror.c

OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean fclean f re

$(NAME): $(OBJECTS) $(INCLUDE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
