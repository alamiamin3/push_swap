/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:01:58 by aalami            #+#    #+#             */
/*   Updated: 2022/10/26 11:23:37 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	size;

	size = len;
	if ((!src && !dst) || len == 0 || src == dst)
		return (dst);
	if (src < dst)
	{
		while (len--)
			*(char *)(dst + len) = *(char *)(src + len);
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
