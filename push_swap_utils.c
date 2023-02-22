/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:27:44 by aalami            #+#    #+#             */
/*   Updated: 2023/02/22 21:59:37 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_args_num(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{printf(" node : %d    %s\n",i, arr[i]);
		i++;}
	return (i);
}

void	ft_sort(int	args, t_stack *a, t_stack *b)
{
	printf("%d\n", args);
	return ;
	if (args <= 3)
		small_sort(a);
	else
		sort_numbers(a, b);
}

void	sort_numbers(t_stack *a, t_stack *b)
{
	t_node *tmp;
	int	size;
	int	index;

	size = stack_size(a);
	tmp = a->top;
	index = get_index(a, get_min(a));
	while (size > 3)
	{
		if (index < (size / 2) && index != 0)
			ra (a);
		else if (index == 0)
		{
			pb (a, b);
			size = stack_size(a);
		}
		else
			rra(a);
		index = get_index(a, get_min(a));
	}
	small_sort(a);
	while (!empty_stack(b))
		pa(b, a);
}

int	is_sorted(char **arr)
{
	int	max;
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	// max = ft_atoi(arr[i]);
	while(arr[i])
	{
		if (i != 0 && max > ft_atoi(arr[i]))
			return (0);
		max = ft_atoi(arr[i]);
		i++;
	}
	return (1);
}

void	small_sort(t_stack *a)
{
	int	index;

	index = get_index(a, get_max(a));
	if (index == 0)
	{
		ra(a);
		if (a->top->data > a->top->next->data)
			sa(a);
		return ;
	}
	else if (index == 1)
	{
		rra(a);
		if (a->top->data > a->top->next->data)
			sa(a);
		return ;
	}
	else
		sa(a);
}

int	get_max(t_stack *s)
{
	t_node	*tmp;
	int	max;
	
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
	int	i;

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