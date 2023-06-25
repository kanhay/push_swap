/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undersix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:32:41 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/13 14:30:49 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_ps *p)
{
	if (p->heada->link->data < p->heada->data
		&& p->heada->link->data < p->heada->link->link->data)
	{
		if (p->heada->data < p->heada->link->link->data)
			swap_a(p);
		else if (p->heada->data > p->heada->link->link->data)
			rotate_a(p);
	}
	else if (p->heada->link->data > p->heada->data
		&& p->heada->link->data > p->heada->link->link->data)
	{
		if (p->heada->data > p->heada->link->link->data)
			rrotate_a(p);
		else if ((p->heada->data < p->heada->link->link->data))
		{
			swap_a(p);
			rotate_a(p);
		}
	}
	else
	{
		swap_a(p);
		rrotate_a(p);
	}
}

int	min_index(t_ps *p)
{
	int		min;
	int		c;
	t_node	*next;

	c = 0;
	min = p->heada->data;
	next = p->heada->link;
	while (next)
	{
		if (next->data < min)
			min = next->data;
		next = next->link;
	}
	next = p->heada;
	while (next && next->data != min)
	{
		if (next->data != min)
			next = next->link;
		c++;
	}
	return (c);
}

void	four(t_ps *p)
{
	int	c;

	c = min_index(p);
	if (c < 2)
	{
		if (c == 1)
			rotate_a(p);
		push_b(p);
	}
	else
	{
		if (c == 2)
			rrotate_a(p);
		rrotate_a(p);
		push_b(p);
	}
	if ((sorted_arg(p->heada)))
		three(p);
	push_a(p);
}

void	five(t_ps *p)
{
	int	c;

	c = min_index(p);
	if (c < 2)
	{
		if (c == 1)
			rotate_a(p);
		push_b(p);
	}
	else if (c > 2)
	{
		if (c == 3)
			rrotate_a(p);
		rrotate_a(p);
		push_b(p);
	}
	else
	{
		rotate_a(p);
		rotate_a(p);
		push_b(p);
	}
	if ((sorted_arg(p->heada)))
		four(p);
	push_a(p);
}

void	underfive(t_ps *p)
{
	if (p->nbr == 1)
		return ;
	else if (p->nbr == 2)
		swap_a(p);
	else if (p->nbr == 3)
		three(p);
	else if (p->nbr == 4)
		four(p);
	else if (p->nbr == 5)
		five(p);
}
