/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:26:20 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/17 16:28:21 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_t(t_ps *p)
{
	int	i;
	int	j;
	int	nb;
	int	s;

	i = 0;
	nb = p->nbr - 1;
	while (i < nb)
	{
		j = i + 1;
		while (j < p->nbr)
		{
			if (p->t[i] > p->t[j])
			{
				s = p->t[i];
				p->t[i] = p->t[j];
				p->t[j] = s;
			}
			j++;
		}
		i++;
	}
}

int	sorted_arg(t_node *list)
{
	t_node	*node;

	node = list;
	while (node->link)
	{
		if (node->data <= node->link->data)
			node = node->link;
		else
			return (1);
	}
	return (0);
}

void	a_nodes(t_ps *p)
{
	int		i;
	t_node	*new;
	t_node	*ptr;

	i = 0;
	ptr = NULL;
	while (p->tab[i])
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return ;
		new->data = ft_atoi(p->tab[i]);
		new->link = NULL;
		if (p->heada == NULL)
		{
			p->heada = new;
			ptr = new;
		}
		else
		{
			ptr->link = new;
			ptr = new;
		}
		i++;
	}
}

void	parsing_call(t_ps *p)
{
	alloc_tab(p);
	check_char(p);
	int_max(p);
	double_arg(p);
}

int	main(int argc, char **argv)
{
	t_ps	p;

	p.ac = argc;
	p.av = argv;
	if (argc < 2)
		exit(0);
	else
		parsing_call(&p);
	p.heada = NULL;
	p.headb = NULL;
	a_nodes(&p);
	release(p.tab);
	if ((sorted_arg(p.heada)))
	{
		if (p.nbr <= 5)
			underfive(&p);
		else
			more(&p);
	}
	free_lists(p.heada);
	exit (0);
}
