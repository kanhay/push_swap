/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:30:59 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 18:01:19 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	int				data;
	struct s_list	*link;
	int				indice;
}	t_node;

typedef struct push_swap
{
	int		nbr;
	char	**tab;
	int		i;
	int		j;
	char	**av;
	int		ac;
	t_node	*heada;
	t_node	*headb;
	int		*t;
}	t_ps;

void	check_char(t_ps *p);
void	int_max(t_ps *p);
void	double_arg(t_ps *p);
void	count_num(t_ps *p);
void	alloc_tab(t_ps *p);
int		ft_perror(void);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, int n);
long	ft_atoi(const char *str);
void	swap_a(t_ps *p);
void	swap_b(t_ps *p);
void	swap_ab(t_ps *p);
void	rotate_a(t_ps *p);
void	rotate_b(t_ps *p);
void	rotate_ab(t_ps *p);
void	rrotate_a(t_ps *p);
void	rrotate_b(t_ps *p);
void	rrotate_ab(t_ps *p);
void	push_a(t_ps *p);
void	push_b(t_ps *p);
void	underfive(t_ps *p);
int		sorted_arg(t_node *list);
void	get_tab(t_ps *p);
void	sort_t(t_ps *p);
void	more(t_ps *p);
void	free_lists(t_node *list);
void	release(char **tab);

#endif