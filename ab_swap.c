/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:44:16 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/13 10:48:23 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap_a(t_ps *p)
{
	swap(p->heada);
	write(1, "sa\n", 3);
}

void	swap_b(t_ps *p)
{
	swap(p->headb);
	write(1, "sb\n", 3);
}

void	swap_ab(t_ps *p)
{
	swap_a(p);
	swap_b(p);
	write(1, "ss\n", 3);
}

void	get_tab(t_ps *p)
{
	t_node	*next;
	int		i;

	next = p->heada;
	i = 0;
	p->t = malloc(sizeof(int) * p->nbr);
	if (p->t == NULL)
		return ;
	while (next)
	{
		p->t[i] = next->data;
		next = next->link;
		i++;
	}
}
