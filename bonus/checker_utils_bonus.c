/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:15:11 by aalami            #+#    #+#             */
/*   Updated: 2023/03/09 16:44:46 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	handle_error(char **arr, t_stack *a, t_stack *b)
{
	write(1, "ERROR\n", 6);
	free_all(arr, a, b);
	exit(EXIT_FAILURE);
}

int	handle_a(char *line, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(line, "sa\n") == 0))
		sa(a);
	else if ((ft_strcmp(line, "ra\n") == 0))
		ra(a);
	else if ((ft_strcmp(line, "rra\n") == 0))
		rra(a);
	else if ((ft_strcmp(line, "pb\n") == 0))
		pb(a, b);
	else
		return (0);
	return (1);
}

int	handle_mutual(char *line, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(line, "rr\n") == 0))
		rr(a, b);
	else if ((ft_strcmp(line, "rrr\n") == 0))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	handle_b(char *line, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(line, "sb\n") == 0))
		sb(b);
	else if ((ft_strcmp(line, "rb\n") == 0))
		rb(b);
	else if ((ft_strcmp(line, "rrb\n") == 0))
		rrb(b);
	else if ((ft_strcmp(line, "pa\n") == 0))
		pa(b, a);
	else
		return (0);
	return (1);
}

void	execute_actions(char *line, char **arr, t_stack *a, t_stack *b)
{
	while (line)
	{
		if (handle_a(line, a, b) || handle_b(line, a, b) || handle_mutual(line,
				a, b))
			free(line);
		else
		{
			free(line);
			handle_error(arr, a, b);
		}
		line = get_next_line(0);
	}
}
