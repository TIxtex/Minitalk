NAME = client
NAME2 = server
SOURCESCLIENT = client_folder/main.c
SOURCESSERVER = server_folder/main.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

.PHONY: all clean fclean f re library mserver

$(NAME): $(SOURCESC)
	cd libft && make
	cd ..
	$(COMPILER) $(FLAGS) $(SOURCESCLIENT) $(LIBFT) -o $(NAME)
	$(COMPILER) $(FLAGS) $(SOURCESSERVER) $(LIBFT) -o $(NAME2)
	
all: $(NAME)
library:
	cd libft && make
	cd ..
clean:
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(NAME2)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean all
