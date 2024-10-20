/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:58:08 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/11 09:40:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
/*
int main(void)
{
    char c = 'A';
    
    printf("'%c'\n", c, ft_tolower(c));
    
    return (0);
}
*/