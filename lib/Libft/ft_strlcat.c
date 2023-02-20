/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:03:46 by aalami            #+#    #+#             */
/*   Updated: 2022/10/27 19:08:01 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	dlen;
	size_t	slen;
	int		i;

	if (!dst && dstsize == 0)
		return (0);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	size = dstsize - ft_strlen(dst) - 1;
	dst = dst + ft_strlen(dst);
	i = 0;
	while (size && src[i])
	{
		dst[i] = src[i];
		size--;
		i++;
	}
	dst[i] = '\0';
	return (slen + dlen);
}
