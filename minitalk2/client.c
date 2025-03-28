/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:23:37 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/16 10:23:37 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*convert_binary(char c)
{
	int		i;
	char	*bits;

	i = 7;
	bits = malloc(9 * sizeof(char));
	if (!bits)
		return (NULL);
	while (i >= 0)
	{
		bits[7 - i] = ((c >> i) & 1) + '0';
		i--;
	}
	bits[8] = '\0';
	return (bits);
}

static void	free_error(char *bit, char *msg)
{
	if (bit)
		free(bit);
	ft_printf("%s\n", msg);
	exit(1);
}

void	send_signal(int pid, char c)
{
	char	*bit;
	int		j;

	bit = convert_binary(c);
	if (!bit)
		free_error(NULL, "Erreur d'allocation mémoire");
	j = 0;
	while (bit[j] != '\0')
	{
		if (bit[j] == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
				free_error(bit, "Erreur lors de l'envoi du signal SIGUSR1");
		}
		else if (bit[j] == '1')
		{
			if (kill(pid, SIGUSR2) == -1)
				free_error(bit, "Erreur lors de l'envoi du signal SIGUSR2");
		}
		usleep(600);
		j++;
	}
	free(bit);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
