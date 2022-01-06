/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:55:36 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/12/23 19:54:40 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst && new)
	{
		p = *lst;
		new->next = 0;
		if (p == 0)
		{
			*lst = new;
			return ;
		}
		while (p->next != 0)
			p = p->next;
		new->prev = p;
		p->next = new;
	}
}
