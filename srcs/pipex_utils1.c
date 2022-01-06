/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:55:05 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/01/06 18:31:07 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*cmd_path(char **path, char **cmd)
{
	char	*line;
	int		i;

	i = -1;
	while (path[++i])
	{
		line = ft_strjoin (path[i], cmd[0]);
		if (!access(line, X_OK))
			return (line);
		free (line);
	}
	if (!access(cmd[0], X_OK))
		return (ft_strdup (cmd[0]));
	ft_exit_cmd (path, cmd);
	return (0);
}

char	**ft_get_path_index(char **env)
{
	int		i;
	char	*line;
	char	**path;

	i = -1;
	while (env[++i])
	{
		line = ft_substr (env[i], 0, 4);
		if (!ft_strncmp(line, "PATH", 4))
			break ;
		free (line);
	}
	free (line);
	if (env[i] == 0)
		exit (0);
	path = ft_split (env[i] + 5, ':');
	i = -1;
	while (path[++i])
	{
		line = path[i];
		path[i] = ft_strjoin (path[i], "/");
		free (line);
	}
	return (path);
}

int	ft_heredoc(char **av)
{
	char	*line;
	char	*str;
	int		fd;

	unlink ("/tmp/.temp");
	fd = ft_open ("/tmp/.temp", 2);
	str = ft_strjoin (av[2], "\n");
	while (1)
	{
		line = get_next_line (0);
		if (!ft_strncmp (line, str, ft_strlen (line)))
			break ;
		ft_putstr_fd (line, fd);
		free (line);
	}
	free (str);
	close (fd);
	fd = ft_open ("/tmp/.temp", 2);
	return (fd);
}
