/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rrotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:42:12 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/17 15:17:31 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*rrotate(t_node *list)
{
	t_node	*tail;
	t_node	*ptail;

	if (list == NULL || list->link == NULL)
		return (NULL);
	tail = list;
	ptail = list;
	while (tail->link)
		tail = tail->link;
	while (ptail->link->link)
		ptail = ptail->link;
	tail->link = list;
	ptail->link = NULL;
	list = tail;
	return (list);
}

void	rrotate_a(t_psb *p)
{
	p->heada = rrotate(p->heada);
}

void	rrotate_b(t_psb *p)
{
	p->headb = rrotate(p->headb);
}

void	rrotate_ab(t_psb *p)
{
	rrotate_a(p);
	rrotate_b(p);
}
