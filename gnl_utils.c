/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:57:40 by khanhayf          #+#    #+#             */
/*   Updated: 2023/05/14 10:45:02 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcmp(void *ptr1, void *ptr2, int s)
{
	char	*p1;
	char	*p2;

	p1 = (char *)ptr1;
	p2 = (char *)ptr2;
	if (s == 0)
		return (0);
	while (s > 1)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		s--;
	}
	return (*p1 - *p2);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

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
