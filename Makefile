NAME = client
NAME2 = server
SOURCESC = client/*.c
SOURCESS = server/*.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

.PHONY: all clean fclean f re library mserver

$(NAME): $(SOURCESC)
$(NAME2): $(SOURCESS)
	
all: library $(NAME) $(NAME2) mclient mserver
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
mclient: $(SOURCESC)
	$(COMPILER) $(FLAGS) $(SOURCESC) -o $(NAME)
mserver: $(SOURCESS)
	$(COMPILER) $(FLAGS) $(SOURCESS) -o $(NAME2)