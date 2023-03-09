/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:23:35 by aalami            #+#    #+#             */
/*   Updated: 2023/03/09 17:16:06 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(char **arr)
{
	t_stack	*a;
	t_stack	*b;

	a = fill_stack(arr);
	b = create_stack();
	if (a && b)
	{
		ft_sort(get_args_num(arr), a, b);
		free_stack(a);
		free_stack(b);
	}
	free_space(arr);
	exit(EXIT_SUCCESS);
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
		if (arr && is_sorted(arr) == 0)
			push_swap(arr);
		else
		{
			if (is_sorted(arr) == 1)
				exit(free_space(arr));
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	else
		exit(EXIT_SUCCESS);
}
