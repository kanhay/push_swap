/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:50:01 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 09:12:46 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_ps *p)
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
	write (1, "pa\n", 3);
}

void	push_b(t_ps *p)
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
	write (1, "pb\n", 3);
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

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char	*d;
	char	*s;
	int		i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
