/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:23:14 by aalami            #+#    #+#             */
/*   Updated: 2023/03/09 16:47:08 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int		i;

	i = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	while (len1 && len2)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
		len1--;
		len2--;
		i++;
	}
	return (0);
}

int	free_all(char **arr, t_stack *a, t_stack *b)
{
	free_space(arr);
	free_stack(a);
	free_stack(b);
	return (0);
}
