/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:05:28 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/04 14:19:37 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	found_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_free_join(char *s1)
{
	free(s1);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s2 == NULL)
		return (s1 = ft_free_join(s1));
	concat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (concat == NULL)
		return (s1 = ft_free_join(s1));
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	free(s1);
	return (concat);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*new;

	if (str == NULL)
		return (NULL);
	i = 0;
	new = (char *)malloc(ft_strlen((char *)str) + 1);
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
