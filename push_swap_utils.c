/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:27:44 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 21:28:55 by aalami           ###   ########.fr       */
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

void	ft_sort(int args, t_stack *a, t_stack *b)
{
	int	*lis;
	int	*sub;
	int	lis_size;

	if (args <= 3)
		small_sort(a);
	else if (args < 10)
		sort_numbers(a, b);
	else
	{
		lis = get_lis(a, args);
		sub = find_lenght(a, args);
		lis_size = get_lis_max(sub, args);
		sort_large_numbers(a, b, lis, lis_size);
	}
}

t_node	*best_move(t_stack *b, t_stack *a)
{
	t_node	*tmp;
	t_node	*max;
	t_node	*b_node;
	int		move;

	tmp = b->top;
	b_node = b->top;
	max = get_higher_num(a, tmp->data);
	move = get_moves_to_a(a, b, tmp, max);
	while (tmp)
	{
		max = get_higher_num(a, tmp->data);
		if (get_moves_to_a(a, b, tmp, max) < move)
		{
			move = get_moves_to_a(a, b, tmp, max);
			b_node = tmp;
		}
		tmp = tmp->next;
	}
	return (b_node);
}

void	move_to_a(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*max;
	int		mid_a;
	int		mid_b;

	mid_a = (stack_size(a)) / 2 ;
	mid_b = (stack_size(b)) / 2;
	tmp = best_move(b, a);
	max = get_higher_num(a, tmp->data);
	if (max->index <= mid_a && tmp->index <= mid_b)
		move_up(a, b, max, tmp);
	else if (max->index > mid_a && tmp->index > mid_b)
		move_bottom(a, b, max, tmp);
	else
	{
		move_to_top_a(a, max);
		move_to_top_b(b, tmp);
		pa(b, a);
	}
}

void	final_sort(t_stack *a)
{
	t_node	*min;
	int		mid;

	min = get_smaller(a);
	mid = stack_size(a) / 2;
	if (min->index <= mid)
	{
		while (a->top->data != min->data)
			ra(a);
	}
	else
	{
		while (a->top->data != min->data)
			rra(a);
	}
}
