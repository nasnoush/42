/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:38:43 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/03 13:26:03 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		i;
	int		r;
	int		s;
	int		count;

	i = 0;
	r = 0;
	s = 1;
	count = 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			s = s * -1;
	if (count == 1)
		return (0);
		i++;
		count++;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i] - 48);
		i++;
	return (r * s);
}
//#include <stdio.h>
//int main(void)
//{
//    char *str = " -79547";
//    printf("%i", ft_atoi(str));
//   return(0);
//}
