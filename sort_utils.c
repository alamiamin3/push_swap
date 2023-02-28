/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:53:05 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 20:20:22 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_numbers(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		size;
	int		index;

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

void	sort_large_numbers(t_stack *a, t_stack *b, int *lis, int max)
{
	t_node	*tmp;
	int		i;
	int		j;

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
	while (!empty_stack(b))
		move_to_a(a, b);
	final_sort(a);
}
