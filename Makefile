NAME = pipex
SRCS = srcs/pipex.c srcs/pipex_utils.c srcs/pipex_utils1.c
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME):
	@cd libft && make re && make clean && cd ..
	@cc $(FLAGS) $(SRCS) -o $(NAME) libft.a
clean:
	@rm -f libft.a
fclean: clean
	@rm -f $(NAME)
re: fclean all