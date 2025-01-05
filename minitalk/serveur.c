/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:23:46 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/16 10:23:46 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	bit_recu = 0;
static int			bit_count = 0;

void	sigusr1_handler(int signum)
{
	bit_recu = bit_recu << 1;
	if (signum == SIGUSR1)
		bit_recu |= 0;
	bit_count++;
	if (bit_count == 8)
	{
		if (bit_recu == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", bit_recu);
		bit_recu = 0;
		bit_count = 0;
	}
}

void	sigusr2_handler(int signum)
{
	bit_recu = bit_recu << 1;
	if (signum == SIGUSR2)
		bit_recu |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (bit_recu == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", bit_recu);
		bit_recu = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("\033[34mServer PID: %d\n\033[0m", getpid());
	ft_printf("\033[30;3mEn attente d'un message..\n\033[0m");

	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);

	while (1)
		pause();
	return (0);
}