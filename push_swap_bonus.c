/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:26:20 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/17 16:21:53 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_op(char *line, t_psb *p)
{
	if (!(ft_memcmp(line, "sa\n", 4)))
		swap_a(p);
	else if (!(ft_memcmp(line, "sb\n", 4)))
		swap_b(p);
	else if (!(ft_memcmp(line, "ss\n", 4)))
		swap_ab(p);
	else if (!(ft_memcmp(line, "ra\n", 4)))
		rotate_a(p);
	else if (!(ft_memcmp(line, "rb\n", 4)))
		rotate_b(p);
	else if (!(ft_memcmp(line, "rr\n", 4)))
		rotate_ab(p);
	else if (!(ft_memcmp(line, "rra\n", 5)))
		rrotate_a(p);
	else if (!(ft_memcmp(line, "rrb\n", 5)))
		rrotate_b(p);
	else if (!(ft_memcmp(line, "rrr\n", 5)))
		rrotate_ab(p);
	else if (!(ft_memcmp(line, "pa\n", 4)))
		push_a(p);
	else if (!(ft_memcmp(line, "pb\n", 4)))
		push_b(p);
	else
		ft_perror();
}

void	a_nodes(t_psb *p)
{
	int		i;
	t_node	*new;
	t_node	*ptr;

	i = 0;
	p->heada = NULL;
	p->headb = NULL;
	while (p->tab[i])
	{
		new = malloc(sizeof(t_node));
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
	release(p->tab);
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

void	parsing_call(t_psb *p)
{
	alloc_tab(p);
	check_char(p);
	int_max(p);
	double_arg(p);
}

int	main(int argc, char **argv)
{
	t_psb	p;
	char	*line;

	p.ac = argc;
	p.av = argv;
	if (argc < 2)
		exit(0);
	else
		parsing_call(&p);
	a_nodes(&p);
	line = get_next_line(0);
	while (line)
	{
		check_op(line, &p);
		free (line);
		line = get_next_line(0);
	}
	free (line);
	if (p.headb == NULL && (sorted_arg(p.heada)) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_lists(p.heada);
	free_lists(p.headb);
	exit (0);
}
