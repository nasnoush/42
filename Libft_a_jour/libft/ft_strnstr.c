/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:12:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/07 12:03:35 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
	j = 0;
		while (haystack[i + j] != '\0' && haystack[i + j]
			== needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *) haystack + i);
			i++;
	}
	return (NULL);
}
