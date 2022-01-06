/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:42:30 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/01/06 18:31:02 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		free (a[i]);
	free (a);
}

void	ft_exit_cmd(char **path, char **line)
{
	ft_putstr_fd ("zsh: command not found: ", 2);
	ft_putendl_fd (line[0], 2);
	ft_free (line);
	ft_free (path);
	exit (0);
}

int	ft_open(char *av, int i)
{
	int		fd;
	char	*line;

	if (i == 1)
		fd = open (av, O_RDONLY, 0777);
	else
		fd = open (av, O_RDWR | O_CREAT, 0777);
	if (fd < 0)
	{
		ft_putstr_fd ("zsh: ", 2);
		line = strerror (errno);
		ft_putstr_fd (line, 2);
		ft_putstr_fd (": ", 2);
		ft_putendl_fd (av, 2);
		exit (0);
	}
	return (fd);
}

void	ft_exit_args(void)
{
	ft_putstr_fd ("\033[0;31m", 2);
	ft_putendl_fd ("Args number is invalid !", 2);
	exit (0);
}

int	main(int ac, char **av, char **env)
{
	t_list	*head;
	char	**path;
	char	**args;
	int		fd[2];
	int		i;

	i = 1;
	if (ac < 5)
		ft_exit_args ();
	if (!ft_strncmp ("here_doc", av[1], ft_strlen (av[1])))
		fd[0] = ft_heredoc (av);
	else
		fd[0] = ft_open (av[1], 1);
	if (!ft_strncmp ("here_doc", av[1], ft_strlen (av[1])))
		i++;
	fd[1] = ft_open (av[ac - 1], 2);
	path = ft_get_path_index (env);
	while (++i < ac - 1)
	{
		args = ft_split (av[i], ' ');
		ft_lstadd_back (&head, ft_lstnew (cmd_path (path, args), args));
	}
	ft_do_all (&head, fd, env);
	wait_execute (&head);
	ft_free_all (&head);
}
