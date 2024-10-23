/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:32:53 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/23 14:07:01 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*size_t read(int fd, void *buf, size_t count)
{
	
}*/

char	*get_next_line(char *str)
{
	char	buffer[32];
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(strlen(str) + 1);
	if (new_str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			new_str[j] = str[i];
			i++;
			j++;
			if (str[i] == '\n')
			{
				break ;
			}
		}
		new_str[j] = str[i];
		j++;
		i++;
	}
	new_str[j] = '\0';
	if (j == 0)
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}

int main()
{
	int fd = 1;
	char *str = "salut\ncomment\nva";
	printf("%s", get_next_line(str));
	free(str);
	return (0);
}