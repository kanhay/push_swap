/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:16:49 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 16:34:11 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*rotate(t_node *list)
{
	t_node	*tail;

	if (list == NULL)
		return (NULL);
	tail = list;
	while (tail->link != NULL)
		tail = tail->link;
	tail->link = list;
	list = list->link;
	tail->link->link = NULL;
	return (list);
}

void	rotate_a(t_psb *p)
{
	p->heada = rotate(p->heada);
}

void	rotate_b(t_psb *p)
{
	p->headb = rotate(p->headb);
}

void	rotate_ab(t_psb *p)
{
	rotate_a(p);
	rotate_b(p);
}

void	free_lists(t_node *list)
{
	t_node	*next;
	t_node	*head;

	head = list;
	while (head)
	{
		next = head->link;
		free (head);
		head = next;
	}
}
