/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:57:13 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 10:45:36 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	c_rows(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i])
				i++;
		}
		else
		i++;
	}
	return (n + 1);
}

void	release(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

char	**c_col(char **tab, char const *s, char c)
{
	char	*tmp;
	int		j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s != c && *s)
				s++;
			tab[j] = (char *)malloc(sizeof(char) * ((s - tmp) + 1));
			if (tab[j] == NULL)
			{
				release (tab);
				return (NULL);
			}
			tab[j][s - tmp] = 0;
			ft_memcpy(tab[j++], tmp, (s - tmp));
		}
		else
			s++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * c_rows(s, c));
	if (tab == NULL)
		return (NULL);
	tab = c_col(tab, s, c);
	return (tab);
}
