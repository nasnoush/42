/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:45:26 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/07 13:45:26 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*expand_buffer(char *buffer, size_t *current_size, size_t data_size)
{
	char	*new_buffer;

	new_buffer = malloc(*current_size + 1);
	if (new_buffer == NULL)
	{
		free(buffer);
		ft_printf("Erreur d'allocation mémoire lors de l'agrandissement\n");
		exit(1);
	}
	ft_memcpy(new_buffer, buffer, data_size);
	free(buffer);
	*current_size += 1;
	return (new_buffer);
}

static void	print_message(char *buffer, size_t buf_size)
{
	char	*final_buf;

	final_buf = malloc(buf_size + 1);
	if (!final_buf)
	{
		free(buffer);
		ft_printf("Erreur d'allocation mémoire lors de l'affichage\n");
		exit(1);
	}
	ft_memcpy(final_buf, buffer, buf_size);
	final_buf[buf_size] = '\0';
	ft_printf("%s\n", final_buf);
	free(final_buf);
}

void	init_buffer(char **buffer, size_t *taille_buff)
{
	if (!(*buffer))
		*buffer = malloc(*taille_buff);
	if (!(*buffer))
	{
		ft_printf("Erreur d'allocation mémoire initiale\n");
		exit(1);
	}
}


void	signal_handler(int signum)
{
	static unsigned char	bit_recu = 0;
	static int				bit_count = 0;
	static char				*buffer = NULL;
	static size_t			buf_size = 0;
	static size_t			taille_buff = 1;

	init_buffer(&buffer, &taille_buff);
	bit_recu = bit_recu << 1 | (signum == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (bit_recu == '\0')
		{
			print_message(buffer, buf_size);
			free(buffer);
			buffer = malloc(1);
			taille_buff = 1;
			buf_size = 0;
		}
		else
		{
			if (buf_size + 1 >= taille_buff)
				buffer = expand_buffer(buffer, &taille_buff, buf_size);
			buffer[buf_size++] = bit_recu;
		}
		bit_recu = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\033[34mServer PID: %d\n\033[0m", getpid());
	ft_printf("\033[30;3mEn attente d'un message...\n\033[0m");
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Erreur lors de l'installation des handlers de signal\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
