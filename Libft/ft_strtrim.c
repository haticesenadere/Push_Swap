/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdere <hdere@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:45:05 by hdere             #+#    #+#             */
/*   Updated: 2025/07/11 16:25:28 by hdere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	s1len;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	s1len = ft_strlen(s1);
	while (s1[start] && ft_set(s1[start], set))
		start++;
	while (s1len > start && ft_set(s1[s1len - 1], set))
		s1len--;
	return (ft_substr(s1, start, s1len - start));
}
