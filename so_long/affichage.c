/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:51:08 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/20 13:50:04 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

static size_t	count_size(long nb)
{
	size_t	size;

	size = 0;
	if (nb <= 0)
	{
		size = 1;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa(int n)
{
	size_t	size;
	long	nb;
	char	*str;

	nb = (long) n;
	size = count_size(nb);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
	{
		str[0] = '0';
	}
	while (nb != 0)
	{
		str[--size] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

void	aff_moove(t_assets *assets, void *mlx, void *window)
{
	char	*nbr_moove;

	nbr_moove = ft_itoa(assets->count_moove);
	/*printf("Affi test : %s\n", nbr_moove);*/
	mlx_string_put(mlx, window, 10, 10, 0x00FFFFFF, nbr_moove);
	free(nbr_moove);
}

