/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:31 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/12/24 17:24:00 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd	*ft_cmdnew(char *path, char **args)
{
	t_cmd	*new;

	new = malloc (sizeof(t_cmd *));
	if (!new)
		return (0);
	new->path = path;
	new->args = args;
	pipe (new->pipe);
	return (new);
}

t_list	*ft_lstnew(char *path, char **args)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == 0)
		return (0);
	new->path = path;
	new->args = args;
	pipe (new->pipe);
	new->next = 0;
	new->prev = 0;
	return (new);
}
