NAME = client
NAME2 = server
SOURCESC = client_folder/*.c
SOURCESS = server_folder/*.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

.PHONY: all clean fclean f re library mserver

$(NAME): $(SOURCESC)
	cd libft && make
	cd ..
all: $(NAME) mclient mserver
library:
	cd libft && make
	cd ..
clean:
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(NAME2)

f: fclean
re: fclean all
mclient: $(SOURCESC)
	$(COMPILER) $(FLAGS) $(SOURCESC) $(LIBFT) -o $(NAME)
mserver: $(SOURCESS)
	$(COMPILER) $(FLAGS) $(SOURCESS) $(LIBFT) -o $(NAME2)