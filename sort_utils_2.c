/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:22:15 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 20:34:38 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_smaller(t_stack *s)
{
	t_node	*tmp;
	t_node	*min;

	tmp = s->top;
	min = s->top;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*get_higher_num(t_stack *a, int n)
{
	t_node	*tmp;
	t_node	*max;

	tmp = a->top;
	max = NULL;
	while (tmp)
	{
		if (tmp->data > n && !max)
			max = tmp;
		if (max && max->data > tmp->data && tmp->data > n)
			max = tmp;
		tmp = tmp->next;
	}
	if (!max)
		max = get_smaller(a);
	return (max);
}

int	is_sorted(char **arr)
{
	int	max;
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i])
	{
		if (i != 0 && max > ft_atoi(arr[i]))
			return (0);
		max = ft_atoi(arr[i]);
		i++;
	}
	return (1);
}

int	get_max(t_stack *s)
{
	t_node	*tmp;
	int		max;

	tmp = s->top;
	max = s->top->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	get_index(t_stack *s, int data)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = s->top;
	while (tmp)
	{
		if (tmp->data == data)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
