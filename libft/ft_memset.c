/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:41:32 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/02 14:53:16 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	
	unsigned char *ptr = (unsigned char *)s;
	while(i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return s;
}
