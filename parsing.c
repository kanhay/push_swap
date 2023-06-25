/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:44:54 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/17 15:05:26 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_char(t_ps *p)
{
	p->i = 0;
	while (p->tab[p->i])
	{
		p->j = 0;
		while (p->tab[p->i][p->j])
		{
			if (!(p->tab[p->i][p->j] >= '0' && p->tab[p->i][p->j] <= '9'))
			{
				if ((p->tab[p->i][p->j] == '+' || p->tab[p->i][p->j] == '-')
				&& p->tab[p->i][p->j + 1] >= '0'
				&& p->tab[p->i][p->j + 1] <= '9' && p->j == 0)
					p->j++;
				else
					ft_perror();
			}
			else
				p->j++;
		}
		p->i++;
	}
}

void	int_max(t_ps *p)
{
	int		i;
	long	n;

	i = 0;
	while (p->tab[i])
	{
		n = ft_atoi(p->tab[i]);
		if (n > 2147483647 || n < -2147483648)
			ft_perror();
		i++;
	}
}

void	double_arg(t_ps *p)
{
	int	i;
	int	j;
	int	ni;
	int	nj;

	i = 0;
	while (p->tab[i])
	{
		j = 1;
		ni = ft_atoi(p->tab[i]);
		while (j < p->nbr)
		{
			nj = ft_atoi(p->tab[j]);
			if (i != j && ni == nj)
				ft_perror();
			j++;
		}
		i++;
	}
}

void	count_num(t_ps *p)
{
	char	**arg;
	int		i;
	int		j;

	i = 1;
	p->nbr = 0;
	while (p->av[i])
	{
		if (p->av[i][0] == '\0')
			ft_perror();
		arg = ft_split(p->av[i++], ' ');
		if (!arg[0])
			ft_perror();
		j = 0;
		while (arg[j++])
			p->nbr++;
		release (arg);
	}
}

void	alloc_tab(t_ps *p)
{
	char	**arg;
	int		i;
	int		j;
	int		k;

	count_num(p);
	p->tab = malloc (sizeof(char *) * (p->nbr + 1));
	if (!p->tab)
		return ;
	p->tab[p->nbr] = NULL;
	i = 1;
	k = 0;
	arg = NULL;
	while (p->av[i])
	{
		arg = ft_split(p->av[i++], ' ');
		j = 0;
		while (arg[j])
		{
			p->tab[k++] = arg[j++];
		}
		free(arg);
	}
}
