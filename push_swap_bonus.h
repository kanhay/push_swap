/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:30:59 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 18:00:39 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE    10
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	int				data;
	struct s_list	*link;
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
}	t_psb;

int		ft_memcmp(void *ptr1, void *ptr2, int s);
void	swap_a(t_psb *p);
void	swap_b(t_psb *p);
void	swap_ab(t_psb *p);
void	rotate_a(t_psb *p);
void	rotate_b(t_psb *p);
void	rotate_ab(t_psb *p);
void	rrotate_a(t_psb *p);
void	rrotate_b(t_psb *p);
void	rrotate_ab(t_psb *p);
void	push_a(t_psb *p);
void	push_b(t_psb *p);
int		ft_perror(void);
long	ft_atoi(const char *str);
void	alloc_tab(t_psb *p);
void	check_char(t_psb *p);
void	int_max(t_psb *p);
void	double_arg(t_psb *p);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	release(char **tab);
void	free_lists(t_node *list);

#endif