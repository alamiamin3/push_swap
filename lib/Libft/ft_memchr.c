/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:06:10 by aalami            #+#    #+#             */
/*   Updated: 2022/10/27 18:58:59 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n - 1 && *(unsigned char *)(s + i) != d)
		i++;
	if (*(unsigned char *)(s + i) == d)
		return ((void *)s + i);
	else
		return (NULL);
}
