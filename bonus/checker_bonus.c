/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:55:35 by aalami            #+#    #+#             */
/*   Updated: 2023/03/09 16:47:41 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_empty(int c, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (argv[i][j] && ((argv[i][j] >= '\t' && argv[i][j] <= '\r')
				|| argv[i][j] == ' '))
			j++;
		if (j == (int)ft_strlen(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*get_args(int argc, char **argv)
{
	int		args;
	char	*buff;
	char	*buff2;
	int		i;

	args = argc - 1;
	buff2 = ft_strdup("");
	i = 1;
	while (args)
	{
		buff = ft_strjoin(buff2, " ");
		free(buff2);
		buff2 = ft_strjoin(buff, argv[i]);
		i++;
		args--;
		free(buff);
	}
	return (buff2);
}

int	check_if_sorted(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!empty_stack(b) || empty_stack(a))
		return (0);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	checker(char **arr)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	line = get_next_line(0);
	a = fill_stack(arr);
	b = create_stack();
	execute_actions(line, arr, a, b);
	if (check_if_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(free_all(arr, a, b));
}

int	main(int argc, char **argv)
{
	char	**arr;
	char	*buff;

	if (argc > 1)
	{
		buff = get_args(argc, argv);
		arr = check_args(buff, argc, argv);
		free(buff);
		if (arr)
			checker(arr);
		else
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	else
		exit(EXIT_SUCCESS);
}
