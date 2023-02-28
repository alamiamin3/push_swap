/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:23:01 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 22:13:07 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_lenght(t_stack *a, int n)
{
	t_node	*prev;
	t_node	*tmp;
	int		*lis;
	int		i;
	int		j;

	tmp = a->top->next;
	lis = init_lis(n);
	j = 1;
	while (j < n)
	{
		prev = a->top;
		i = 0;
		while (i < j)
		{
			if (prev->data < tmp->data && lis[j] <= lis[i])
				lis[j] = lis[i] + 1;
			prev = prev->next;
			i++;
		}
		tmp = tmp->next;
		j++;
	}
	return (lis);
}

int	*get_lis(t_stack *a, int n)
{
	int		*lis;
	int		*sub;
	int		max_index;
	t_node	*tmp;
	int		lis_size;

	lis = find_lenght(a, n);
	lis_size = get_lis_max(lis, n);
	sub = (int *)malloc(sizeof(int) * lis_size);
	max_index = get_lis_max_index(lis, n, lis_size);
	while (lis_size >= 1)
	{
		tmp = get_node_by_index(a, get_lis_index(lis, lis_size, max_index));
		sub[lis_size - 1] = tmp->data;
		lis_size --;
		max_index = get_lis_index(lis, lis_size, max_index - 1);
	}
	return (sub);
}

int	*init_lis(int n)
{
	int	*lis;
	int	size;

	size = 0;
	lis = malloc(sizeof(int) * n);
	if (!lis)
		return (0);
	while (size < n)
	{
		lis[size] = 1;
		size ++;
	}
	return (lis);
}

int	get_lis_max(int *lis, int n)
{
	int	i;
	int	max;

	max = 1;
	i = 0;
	while (i < n)
	{
		if (lis[i] > max)
			max = lis[i];
		i++;
	}
	return (max);
}

int	get_lis_max_index(int *lis, int n, int num)
{
	int	i;
	int	index;

	i = n;
	while (i >= 0)
	{
		if (lis[i] == num)
			index = i;
		i--;
	}
	return (index);
}
