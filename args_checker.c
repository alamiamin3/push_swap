/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:55 by aalami            #+#    #+#             */
/*   Updated: 2023/03/05 14:28:41 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+') && str[i + 1])
			i++;
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_dup(char **arr)
{
	int	i;
	int	j;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (j != i && ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i ++;
	}
	return (1);
}

int	is_int(char *str)
{
	int	max;
	int	min;

	max = 2147483647;
	min = -2147483648;
	if (ft_atoi(str) > max || ft_atoi(str) < min || !check_nbr(str))
		return (0);
	return (1);
}

int	free_space(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (0);
}

char	**check_args(char *buff, int argc, char **argv)
{
	char	**arr;
	int		i;

	arr = ft_split(buff, ' ');
	if (!arr || !check_dup(arr) || !check_empty(argc, argv))
	{
		if (!check_dup(arr) || !check_empty(argc, argv))
			free_space(arr);
		return (0);
	}
	i = 0;
	while (arr[i])
	{
		if (is_int(arr[i]))
			i++;
		else
		{
			free_space(arr);
			return (0);
		}
	}
	if (i != 0)
		return (arr);
	else
	{
		free_space(arr);
		return (0);
	}
}
