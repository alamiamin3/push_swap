/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:33:21 by aalami            #+#    #+#             */
/*   Updated: 2023/02/24 19:26:57 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_node	*tmp;
	int	i;

	if (empty_stack(stack))
		return (0);
	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	get_min(t_stack *s)
{
	t_node	*tmp;
	int	min;
	
	tmp = s->top;
	min = s->top->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	*find_lenght(t_stack *a, int n)
{
	int 	*lis;
	t_node	*prev; // check previews cells of the current cell
	t_node	*tmp; // check array's cells
	int	i;
	int	j;

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
	int	*lis;
	int	*sub;
	int	max_index;
	int	index;
	t_node	*tmp;
	int	lis_size;
	int	i;

	lis = find_lenght(a, n);
	i = 0;
	lis_size = get_lis_max(lis, n);
	// printf("%d\n",lis_size);
	sub = (int *)malloc(sizeof(int) * lis_size);
	max_index =  get_lis_max_index(lis, n, lis_size);
	while (lis_size >= 1)
	{
		index =  get_lis_index(lis,lis_size, max_index);
		i = lis_size - 1;
		tmp = get_node_by_index(a, index);
		sub[i] = tmp->data;
		lis_size --;
		max_index =  get_lis_index(lis,lis_size, max_index - 1);
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

t_node	*get_node_by_index(t_stack *a, int index)
{
	t_node *tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->index == index)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

int	get_lis_index(int *lis, int num, int max_index)
{
	int	i;

	i = max_index;
	while (i >= 0)
	{
		if (lis[i] == num)
			break;
		i--;
	}
	return (i);
}
