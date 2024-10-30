/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:32:53 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/30 14:21:23 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char **stock)
{
	char	*line;
	int		i;
	char	*temp;

	i = 0;
	if (*stock == NULL)
		return (NULL);
	while ((*stock)[i] != '\0' && (*stock)[i] != '\n')
		i++;
	line = (char *)malloc (i + 2);
	if (line == NULL)
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
	strlcpy(line, *stock, i + 2);
	if ((*stock)[i] == '\n')
		temp = ft_strdup(*stock + i + 1);
	else
		temp = ft_strdup(*stock + i);
	if (temp == NULL)
	{
		free(line);
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
	free(*stock);
	*stock = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_lu;
	char		*new_stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	bytes_lu = read(fd, buffer, BUFFER_SIZE);
	while (bytes_lu > 0)
	{
		buffer[bytes_lu] = '\0';
		new_stock = ft_strjoin(stock, buffer);
		if (new_stock == NULL)
		{
			free(stock);
			stock = NULL;
			return (NULL);
		}
		stock = new_stock;
		if (found_line(stock) != -1)
			break ;
		bytes_lu = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_lu < 0 || (bytes_lu == 0 && (stock == NULL || *stock == '\0')))
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = ft_line(&stock);
	if (line == NULL)
	{
		free(stock);
		stock = NULL;
	}
	return (line);
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


