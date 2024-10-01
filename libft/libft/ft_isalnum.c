/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:49:18 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/01 12:19:17 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
//#include <stdio.h>
//int main(void)
//{
//	printf("%d", ft_isalnum("//lut458"));
//	return (0);
//}
