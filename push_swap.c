/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:23:35 by aalami            #+#    #+#             */
/*   Updated: 2023/03/05 16:02:12 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leaks(void)
{
	system("leaks push_swap");
}

int	check_empty(int c, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (argv[i][j] && ((argv[i][j] >= '\t' && argv[i][j] <= '\r') || 
			argv[i][j] == ' '))
			j++;
		if (j == (int)ft_strlen(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	// t_node *temp;
	int	args;
	char	*buff;
	char	*buff2;
	int	i;
	char	**arr;
	// atexit(leaks);
	if (argc > 1)
	{
		args = argc - 1 ;
		buff = ft_strdup("");
		buff2 = ft_strdup("");
		i = 1;
		
		while (args)
		{
			if (i == 1)
				free(buff);
			buff = ft_strjoin(buff2, " ");
			free (buff2);
			buff2 = ft_strjoin(buff, argv[i]);
			i++;
			args--;
			free (buff); 
		}
		arr = check_args(buff2, argc, argv);
		if (arr && is_sorted(arr) == 0)
		{
			stack_a = fill_stack(arr);
			stack_b = create_stack();
			ft_sort(get_args_num(arr), stack_a, stack_b);
			free_space(arr);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (is_sorted(arr) == 1)
			{
				free_space(arr);
				exit (0);
			}
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
		free (buff2);
	}
	else
		exit(0);
}

