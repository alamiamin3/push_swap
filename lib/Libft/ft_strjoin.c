/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:23:28 by aalami            #+#    #+#             */
/*   Updated: 2022/10/26 16:06:35 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(char const *s1, char const *s2)
{
	size_t	size;
	char	*p;

	size = (ft_strlen(s1) + ft_strlen(s2));
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	p = allocate(s1, s2);
	if (!p)
		return (NULL);
	while (*(s1 + i))
	{
		p[i] = s1[i];
		i++;
	}
	while (*(s2 + j))
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
