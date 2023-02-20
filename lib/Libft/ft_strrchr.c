/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:13:06 by aalami            #+#    #+#             */
/*   Updated: 2022/10/25 18:20:31 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (c < 0)
		return (0);
	i = (ft_strlen(s));
	while (i && ((char)s[i] != (char)c))
		i--;
	if ((char)s[i] == (char)c)
		return ((char *)s + i);
	else
		return (NULL);
}
