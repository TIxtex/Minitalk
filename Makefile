NAME_CLIENT = client
NAME_SERVER = server
NAME = $(NAME_CLIENT) $(NAME_SERVER)
CC = clang -std=c11
CFLAGS = -Wall -Wextra -Werror

TOOLS = tools_folder/tools.a
INCLUDE = \
minitalk.h tools_folder/tools.h

SOURCES_CLIENT = client_folder/main.c
SOURCES_SERVER = server_folder/main.c
SOURCES = $(SOURCES_CLIENT) $(SOURCES_SERVER)

OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS = $(OBJECTS_CLIENT) $(OBJECTS_SERVER)

.PHONY: all clean fclean f re library

$(NAME): $(OBJECTS) $(TOOLS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) $(TOOLS) -o $(NAME_CLIENT)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) $(TOOLS) -o $(NAME_SERVER)
	
$(TOOLS): tools_folder/Makefile
	cd tools_folder/ && make
	cd ../

all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
	cd tools_folder/ && make clean
	cd ../
fclean: clean
	/bin/rm -rf $(NAME_CLIENT)
	/bin/rm -rf $(NAME_SERVER)
	/bin/rm -rf $(TOOLS)
f: fclean
re: fclean all
