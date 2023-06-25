/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:44:16 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 10:44:24 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node *list)
{
	t_node	*ptr;
	int		d;

	if (list == NULL || list->link == NULL)
		return ;
	ptr = list->link;
	d = list->data;
	list->data = ptr->data;
	ptr->data = d;
}

void	swap_a(t_psb *p)
{
	swap(p->heada);
}

void	swap_b(t_psb *p)
{
	swap(p->headb);
}

void	swap_ab(t_psb *p)
{
	swap_a(p);
	swap_b(p);
}
