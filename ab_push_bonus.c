/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:50:01 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 10:59:04 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_a(t_psb *p)
{
	t_node	*topush;

	if (p->headb == NULL)
		return ;
	topush = p->headb;
	if (p->headb->link)
		p->headb = p->headb->link;
	else
		p->headb = NULL;
	if (p->heada == NULL)
	{
		topush->link = NULL;
		p->heada = topush;
	}
	else
	{
		topush->link = p->heada;
		p->heada = topush;
	}
}

void	push_b(t_psb *p)
{
	t_node	*topush;

	if (p->heada == NULL)
		return ;
	topush = p->heada;
	p->heada = p->heada->link;
	if (p->headb == NULL)
	{
		topush->link = NULL;
		p->headb = topush;
	}
	else
	{
		topush->link = p->headb;
		p->headb = topush;
	}
}

int	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

long	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long		r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r = r + (str[i] - 48);
		i++;
	}
	return (r * s);
}
