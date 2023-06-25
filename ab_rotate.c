/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:16:49 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/13 14:11:06 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_a(t_ps *p)
{
	p->heada = rotate(p->heada);
	write(1, "ra\n", 3);
}

void	rotate_b(t_ps *p)
{
	p->headb = rotate(p->headb);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_ps *p)
{
	rotate_a(p);
	rotate_b(p);
	write(1, "rr\n", 3);
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
