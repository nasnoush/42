/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:08 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/02 13:28:53 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t = i;
	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s + i)) == ((unsigned char)c))
		{
			return ((void *)(s + 1));
		}
		i++;
	}
	return (NULL);
}
