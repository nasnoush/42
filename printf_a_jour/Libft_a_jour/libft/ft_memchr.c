/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:08 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/11 09:33:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == ((unsigned char)c))
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
    char str[] = "Hello World";
    char *result = (char *)ft_memchr(str, 'W', 11);

    if (result)
        printf("Caractère trouvé : %s\n", result);
    else
        printf("Caractère non trouvé\n");

    return (0);
}
*/
