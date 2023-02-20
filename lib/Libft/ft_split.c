/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:52:06 by aalami            #+#    #+#             */
/*   Updated: 2023/02/15 16:40:55 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_elm(char const *s, char c)
{
	size_t	i;
	int		elm;

	elm = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (s[i] != c)
				elm++;
			else if (s[i + 1] != c)
				elm++;
		}
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			elm++;
		}
		i++;
	}
	return (elm);
}

static char	**free_space(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			words++;
		}
		else
			break ;
		s++;
	}
	return (words);
}

static char	*allocate(char const *s, int words)
{
	char	*new;
	int		size;

	size = words;
	new = (char *)malloc(words + 1);
	if (!new)
		return (0);
	while (words--)
		*new ++ = *s++;
	*new = '\0';
	return (new - size);
}

char	**ft_split(char const *s, char c)
{
	t_split	split;

	if (!s)
		return (NULL);
	split.elm = count_elm(s, c);
	split.i = 0;
	split.ptr = (char **)malloc(sizeof(char *) * (split.elm + 1));
	if (!split.ptr)
		return (NULL);
	while (split.elm && *s)
	{
		if (*s != c)
		{
			split.ptr[split.i] = allocate(s, count_words(s, c));
			if (!split.ptr[split.i])
				return (free_space(split.ptr, split.i));
			s = s + count_words(s, c);
			split.elm--;
			split.i++;
		}
		s++;
	}
	split.ptr[split.i] = NULL;
	return (split.ptr);
}
