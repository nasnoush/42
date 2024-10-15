/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:02:22 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/15 11:29:58 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found_conv(const char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == c)
			{
				return (1);
			}
		}
	}
	return (0);
}


int	ft_printf(const char *format)
{
	int	i;
	
	i = 0;
	if (format == NULL)
	{
		return NULL;
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ft_putchar('')
			}
		}
	}
}

int	ft_printf(const char *,...)
{
	va_list args;
	va_start(args, format);
}