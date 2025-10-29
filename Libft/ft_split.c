/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdere <hdere@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:48:50 by hdere             #+#    #+#             */
/*   Updated: 2025/07/12 23:13:49 by hdere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_arr(char **arr, int j)
{
	while (--j >= 0)
		free(arr[j]);
	free(arr);
}

static int	fill_array(char **arr, char const *s, char c)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[j] = ft_substr(s, start, i - start);
			if (!arr[j])
				return (free_arr(arr, j), 0);
			j++;
		}
	}
	return (arr[j] = NULL, 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_array(arr, s, c))
		return (NULL);
	return (arr);
}
