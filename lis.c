/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:02:25 by aalami            #+#    #+#             */
/*   Updated: 2023/02/24 17:42:25 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*find_lenght(int *arr, int n)
{
	int 	*lis;
	// int	len;
	int	size;
	int	i; // check previews cells of the current cell
	int	j; // check array's cells

	// len = 1;
	size = 0;
	lis = malloc(sizeof(int) * n);
	j = 1;
	while (size < n)
	{
		lis[size] = 1;
		size ++;
	}
	while (j < n)
	{
		i = 0;
		while (i < j)
		{
			if (arr[i] < arr[j] && lis[j] <= lis[i])
			{
				lis[j] = lis[i] + 1;
				// len = lis[j];
			}
			i++;
		}
		j++;
	}
	return (lis);
}
int	get_lis_max(int *lis, int n)
{
	int	i;
	int	max;

	max = 1;
	i = 0;
	while (i < n)	
	{
		if (lis[i] > max)
			max = lis[i];
		i++;
	}
	printf("%d from fun\n", max);
	return (max);
}
int	get_lis_max_index(int *lis, int n, int num)
{
	int	i;
	int	index;

	i = n;
	while (i >= 0)
	{
		if (lis[i] == num)
			index = i;
		i--;
	}
	return (index);
}

int	get_lis_index(int *lis, int n, int num, int max_index)
{
	int	i;

	i = max_index;
	while (i >= 0)
	{
		if (lis[i] == num)
			break;
		i--;
	}
	return (i);
}
int	*get_lis(int *arr, int n)
{
	int	*lis;
	int	*sub;
	int	max_index;
	int	index;
	int	lis_size;
	int	i;

	lis = find_lenght(arr, n);
	lis_size = get_lis_max(lis, n);
		printf ("%d  ", lis_size);
	sub = (int *)malloc(sizeof(int) * lis_size);
		max_index =  get_lis_max_index(lis, n, lis_size);
	while (lis_size >= 1)
	{
		
		printf ("%d  ", max_index);
		index =  get_lis_index(lis, n, lis_size, max_index);
		i = lis_size - 1;
		sub[i] = arr[index];
		lis_size --;
		max_index =  get_lis_index(lis, n, lis_size, max_index - 1);
		
	}
		printf ("\n");
	return (sub);
}

int	main()
{
	int arr[12] = {152, 158, 255, 806, 141, 560, 654, 794, 836, 219, 538, 832};
	int i;
	int *lis = find_lenght(arr, 12);
	int max = get_lis_max (lis, 12);
		printf("%d \n",max);
	int *sub = get_lis(arr, 12);
	i = 0;
	while (i < max)
	{
		printf("%d ",sub[i]);
		i++;
	}
		printf("\n");
	
}
