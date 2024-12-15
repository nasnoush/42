/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:07:56 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 19:07:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	bit_recu = 0;
static int				bit_count = 0;

void	sigusr1_handler(int	signum)
{
	(void)signum;

	bit_recu = bit_recu << 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &bit_recu, 1);
		bit_recu = 0;
		bit_count = 0;
	}
}

void	sigusr2_handler(int signum)
{
	(void)signum;
	
	bit_recu = bit_recu << 1;
	bit_recu |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &bit_recu, 1);
		bit_recu = 0;
		bit_count = 0;
	}
}

int main(void)
{
	ft_printf("Server PID: %d\n", getpid());

	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);

	while(1)
	{
		pause();
	}
	return (0);
}
