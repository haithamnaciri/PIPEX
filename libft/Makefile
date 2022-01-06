SRCS = ft_strlen.c ft_strncmp.c ft_strdup.c ft_substr.c ft_strchr.c ft_strjoin.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c get_next_line.c
CFLAGS = -Wall -Wextra -Werror
NAME = ../libft.a
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
%.o: %.c
	 @cc -o $@ -c $<
all : $(NAME)
clean :
	@rm -f $(OBJS) $(BONUSOBJS)
fclean : clean
	@rm -f $(NAME)
re : fclean all
