/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:53:48 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/01/06 18:29:41 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_open_pipe(t_list **head, int *fd)
{
	if (!(*head)->prev && (*head)->next)
	{
		dup2 (fd[0], 0);
		dup2 ((*head)->pipe[1], 1);
		close ((*head)->pipe[0]);
		close ((*head)->pipe[1]);
	}
	if ((*head)->prev && (*head)->next)
	{
		dup2 ((*head)->prev->pipe[0], 0);
		dup2 ((*head)->pipe[1], 1);
		close ((*head)->prev->pipe[0]);
		close ((*head)->prev->pipe[1]);
	}
	if ((*head)->prev && !(*head)->next)
	{
		dup2 ((*head)->prev->pipe[0], 0);
		dup2 (fd[1], 1);
		close ((*head)->prev->pipe[0]);
	}
}

void	ft_free_all(t_list **list)
{
	t_list	*head;

	head = *list;
	while (head)
	{
		free (head->path);
		ft_free (head->args);
		close (head->pipe[0]);
		close (head->pipe[1]);
		if (head->next)
		{
			head = head->next;
			free (head->prev);
		}
		else
		{
			free (head);
			head = head->next;
		}	
	}
}

void	ft_do_all(t_list **list, int *fd, char **env)
{
	t_list	*head;
	int		i;

	head = *list;
	while (head)
	{
		head->pid = fork();
		if (!head->pid)
		{
			ft_open_pipe (&head, fd);
			i = execve (head->path, head->args, env);
			if (i < 0)
				ft_exit_cmd (head->args, head->args);
		}
		close(head->pipe[1]);
		head = head->next;
	}
}

void	close_pipe(t_list **list)
{
	t_list	*head;

	head = *list;
	while (head)
	{
		close (head->pipe[0]);
		close (head->pipe[1]);
		head = head->next;
	}
}

void	wait_execute(t_list **list)
{
	t_list	*head;

	head = *list;
	close_pipe(list);
	while (head)
	{
		waitpid (head->pid, 0, 0);
		head = head->next;
	}
}
