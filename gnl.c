/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:58:38 by nadahman          #+#    #+#             */
/*   Updated: 2025/03/25 11:24:26 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFERSIZE 10
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	if (str == NULL)
		return (NULL);
	i = 0;
	new = (char *)malloc(strlen((char *)str) + 1);
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

int ft_strchr(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strdup(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_free_join(char *s1)
{
	free(s1);
	return (NULL);
}

char	*ft_free_stock(char *stock)
{
	free(stock);
	stock = NULL;
	return (stock);
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
	concat = (char *)malloc((strlen(s1) + strlen(s2) + 1));
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


char *get_next_line(int fd)
{
	static char *stock = NULL;
	char buffer[BUFFERSIZE + 1];
	int byte_lu;
	char *new_stock;
	
	char *line;
	int i;
	char *tmp;
	
	if (fd < 0 || BUFFERSIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	byte_lu = 1;
	while (byte_lu > 0)
	{
		byte_lu = read(fd, buffer, BUFFERSIZE);
		if (byte_lu <= 0)
			break ;
		buffer[byte_lu] = '\0';
		new_stock = ft_strjoin(stock, buffer);
		if (new_stock == NULL)
		{
			free(stock);
			stock = NULL;
			return (NULL);
		}
		stock = new_stock;
		if (ft_strchr(stock, '\n') == 1)
			break ;
	}
	if (byte_lu < 0 || (byte_lu == 0 && (stock == NULL || *stock == '\0')))
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	
	
	// extraire la ligne 
	i = 0;
	if (stock == NULL || stock[i] == '\0')
		return (NULL);
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (line == NULL)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	ft_strlcpy(line, stock, i + 2);
	if (stock[i] == '\n')
		tmp = ft_strdup(stock + i + 1);
	else
		tmp = NULL;
	free(stock);
	stock = tmp;
	return (line);
}



#include <stdio.h>
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
}