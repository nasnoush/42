/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:05:28 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/24 13:34:52 by nadahman         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	j = 0;
	concat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (concat == NULL)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat = "\0";
	return (concat);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc((ft_strlen(str)) + 1);
	if (new == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new = "\0";
	return (new);
}