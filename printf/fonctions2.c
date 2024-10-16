/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:43:19 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/16 17:10:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (0);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr_unsigned(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_hex(unsigned int nb, char format)
{
	char	*base;
	int		count;

	base = NULL;
	count = 0;
	if (format == 'x')
	{
		base = "0123456789abcdef";
	}
	else if (format == 'X')
	{
		base = "0123456789ABCDEF";
	}
	if (base != NULL)
	{		
		if (nb >= 16)
		{
			count += ft_putnbr_hex(nb / 16, format);
		}
	}
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	adress;
	int				count;

	if (ptr == NULL)
	{
		count += ft_putstr("0x0");
		return (0);
	}
	count = 0;
	adress = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_putnbr_hex(adress, 'x');
	return (count);
}
