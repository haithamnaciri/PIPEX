/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:01 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/12/24 18:17:26 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct s_cmd
{
	char	*path;
	char	**args;
	int		pipe[2];
}	t_cmd;

typedef struct s_list
{
	char			*path;
	char			**args;
	int				pipe[2];
	int				pid;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char*s2, size_t n);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(char *path, char **args);
int		ft_lstsize(t_list *lst);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif