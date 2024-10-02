/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:43:37 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/02 13:54:35 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;

	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	while(i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}