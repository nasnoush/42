/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:32:53 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/24 13:57:33 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_lu;
	int			i;
	int			j;
	char		*temp;
	int			start_index;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	while ((bytes_lu = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_lu] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (found_line(stock))
			break ;
	}
	if (found_line(stock))
	{
		j = 0;
		while (stock[i] != '\0' && stock[i] != '\n')
		i++;
		line = (char *)malloc (i + 2);
		{
			if (line == NULL)
				return (NULL);
		}
		while (j < 1)
		{
			line[j] = stock[j];
			j++; 
		}
		line[j] = '\n';
		line[j + 1] = '\0'; 

		start_index = i;
		if (stock[i] == '\n')
		{
			start_index = start_index + 1;
		}
		temp = ft_strdup(&stock[start_index]);
		free(stock);
		stock = temp;
		return (line);
	}
	if (bytes_lu == 0)
	{
		free(stock);
		if (stock == NULL)
		return (NULL);
	}
	return (NULL);
}

/*#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

    fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
