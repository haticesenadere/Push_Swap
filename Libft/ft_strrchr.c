/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdere <hdere@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:24:04 by hdere             #+#    #+#             */
/*   Updated: 2025/07/11 16:31:52 by hdere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = (char *)s;
	while ((i >= 0) && (ptr[i] != (unsigned char)c))
		i--;
	if (ptr[i] == (unsigned char)c)
		return (&ptr[i]);
	return (NULL);
}
