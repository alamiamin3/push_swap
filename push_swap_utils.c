/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:27:44 by aalami            #+#    #+#             */
/*   Updated: 2023/02/25 19:14:17 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_args_num(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_sort(int	args, t_stack *a, t_stack *b)
{
	int	*lis;
	int	*sub;
	t_node	*tmp;

	int	lis_size;
	if (args <= 3)
		small_sort(a);
	else if (args <= 10)
		sort_numbers(a, b);
	else
	{
		lis = get_lis(a, args);
		sub = find_lenght(a, args);
		lis_size = get_lis_max(sub, args);
		sort_large_numbers(a, b, lis, lis_size);
		tmp = a->top;
			while (tmp)
		{
			printf("%d ",tmp->data);
			tmp=tmp->next;
		}
			printf("\n  size of lis :%d\n",lis_size);
	}
		
}

void	sort_large_numbers(t_stack *a, t_stack *b, int *lis, int max)
{
	t_node	*tmp;
	int	i;
	int	j;
	t_node	*max_a;

	i = 0;
	j = stack_size(a);
	while (j)
	{
		tmp = a->top;
		if (tmp->data == lis[i] && i < max)
		{
			ra(a);
			i++;
		}
		else
			pb(a, b);
		j--;
	}
	tmp = b->top;
	while (tmp)
	{
		max_a = get_higher_num(a,tmp->data);
		printf(" b[%d] = %d < a[%d] = %d\n",tmp->index, tmp->data, max_a->index, max_a->data);
		tmp = tmp->next;
	}
}
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
t_node	*get_higher_num(t_stack *a,int n)
{
	t_node	*tmp;
	t_node	*max;
	// int	i;
	
	// i = 0;
	tmp = a->top;
	max = NULL;
	while (tmp)
	{
		if (tmp->data > n && !max)
		{
			max = tmp;
			// i++;
		}
		if (max && max->data > tmp->data && tmp->data > n)
		{
			max = tmp;
			// i++;
		}
		tmp = tmp->next;
	}
	if (!max)
		max = get_smaller(a);
	return (max);
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