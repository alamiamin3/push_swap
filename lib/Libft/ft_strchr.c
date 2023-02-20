/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:58:48 by aalami            #+#    #+#             */
/*   Updated: 2022/10/27 19:07:55 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c < 0)
		return (0);
	i = 0;
	while (s[i] && (char)s[i] != (char)c)
		i++;
	if ((char)s[i] == (char)c)
		return ((char *)s + i);
	else
		return (NULL);
}
