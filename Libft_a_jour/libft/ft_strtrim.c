/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:50:05 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/08 14:10:32 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*mem;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && is_in(start, set))
	{
		start++;
	}
	while (end > start && is_in(s1[end - 1], set))
	{
		end--;
	}
	mem = (char *)malloc(end - start + 1);
	if (mem == NULL)
		return (NULL);
	ft_strncpy(mem, s1 + start, end - start);
	mem[end - start] = '\0';
	return (mem);
}
