/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:44:01 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 11:44:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*convert_binary(char c)
{
	int	i;
	char *bits;

	i = 7;
	bits = malloc(9 * sizeof(char));
	if (!bits)
		return NULL ;
	while (i >= 0)
	{
		bits[7 - i] = ((c >> i) & 1) + '0';
		i--;
	}
	bits[8] = '\0';
	return (bits);
}

void	send_signal(int PID, char c)
{
	char	*bit;
	int		j;

	bit = convert_binary(c);
	if (!bit)
	{
		ft_printf("Erreur d'allocation mémoire\n");
		return ;
	}	
	j = 0;
	while (bit[j] != '\0')
	{
		if (bit[j] == '0')
		{
			if (kill(PID, SIGUSR1) == -1)
			{
				ft_printf("Erreur lors de l'envoi du signal SIGUSR1\n");
				free(bit);
				return ;
			}
		}
		else if (bit[j] == '1')
		{
			if (kill(PID, SIGUSR2) == -1)
			{
				ft_printf("Erreur lors de l'envoi du signal SIGUSR2\n");
				free(bit);
				return ;
			}
		}
		usleep(1);
		j++;
	}
	free(bit);
}
/*void	client_message(t_signal s_signal)
{
	if (s_signal.PID < 0)
	{
		ft_printf("PID non valide !");
		return ;
	}
	if (!s_signal.message)
	{
		ft_printf("Message non valide !");
		return ;
	}
	send_signal(s_signal);
}*/

int main(int argc, char **argv)
{
	int	PID;
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}

	PID = atoi(argv[1]);
	if (PID <= 0)
	{
		ft_printf("PID invalide !\n");
		return (1);
	}

	i = 0;
	while (argv[2][i] != '\0')
	{
		send_signal(PID, argv[2][i]);
		i++;
	}
	send_signal(PID, '\0');

	return (0);
}