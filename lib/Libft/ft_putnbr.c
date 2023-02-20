/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:56:36 by aalami            #+#    #+#             */
/*   Updated: 2023/01/08 15:00:21 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long n, int *num)
{
	if (n >= 0 && n < 10)
		*num += ft_putchar(('0' + n));
	else if (n < 0)
	{
		*num += ft_putchar('-');
		ft_putnbr((n * -1), num);
	}
	else
	{
		ft_putnbr(n / 10, num);
		ft_putnbr(n % 10, num);
	}
	return (*num);
}
