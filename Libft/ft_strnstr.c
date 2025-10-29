/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdere <hdere@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:23:32 by hdere             #+#    #+#             */
/*   Updated: 2025/07/11 15:24:58 by hdere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	little_len;

	little_len = ft_strlen(little);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && little_len <= len - i)
	{
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
