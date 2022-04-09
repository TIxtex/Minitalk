NAME_CLIENT = client
NAME_SERVER = server
NAME = \
$(NAME_CLIENT) \
$(NAME_SERVER)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
INCLUDE = \
minitalk.h \
libft/libft.h

SOURCES_CLIENT = \
client_folder/main.c
SOURCES_SERVER = \
server_folder/main.c
SOURCES = \
$(SOURCES_CLIENT) \
$(SOURCES_SERVER)

OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS = \
$(OBJECTS_CLIENT) \
$(OBJECTS_SERVER)

.PHONY: all clean fclean f re library

$(NAME): $(OBJECTS) $(INCLUDE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) $(LIBFT) -o $(NAME_SERVER)
	
$(LIBFT): libft/Makefile
	cd libft/ && make
	cd ../

all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
	cd libft/ && make clean
	cd ../
fclean: clean
	/bin/rm -rf $(NAME_CLIENT)
	/bin/rm -rf $(NAME_SERVER)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean all
