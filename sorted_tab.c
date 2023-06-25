/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:16:47 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 16:23:42 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_a(t_ps *p)
{
	t_node	*next;
	int		i;

	next = p->heada;
	i = 0;
	while (i < p->nbr)
	{
		if (next->data == p->t[i])
		{
			next->indice = i++;
			next = p->heada;
		}
		next = next->link;
		if (!next)
			next = p->heada;
	}
	free (p->t);
}

void	move2b(t_ps *p)
{
	int	i;
	int	j;

	i = 0;
	if (p->nbr <= 100)
		j = 15;
	else
		j = 37;
	while (p->heada)
	{
		if (p->heada->indice < i)
		{
			push_b(p);
			i++;
		}
		else if (p->heada->indice < (i + j))
		{
			push_b(p);
			rotate_b(p);
			i++;
		}
		else
			rotate_a(p);
	}
}

int	max_pos(t_ps *p, int max)
{
	int		pos;
	t_node	*next;

	pos = 0;
	next = p->headb;
	while (next && next->indice != max)
	{
		next = next->link;
		pos++;
	}
	return (pos);
}

void	sort_a(t_ps *p)
{
	int	max;
	int	m_pos;

	max = p->nbr - 1;
	while (p->headb)
	{
		m_pos = max_pos(p, max);
		if (m_pos >= (max + 1) / 2)
		{
			while (p->headb && p->headb->indice != max)
				rrotate_b(p);
		}
		else
		{
			while (p->headb && p->headb->indice != max)
				rotate_b(p);
		}
		push_a(p);
		max--;
	}
}

void	more(t_ps *p)
{
	get_tab(p);
	sort_t(p);
	index_a(p);
	move2b(p);
	sort_a(p);
}
