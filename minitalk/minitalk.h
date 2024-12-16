/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:49:00 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 12:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

/*# define SIGUSR1 10
# define SIGUSR2 12*/

typedef struct s_signal
{
	int		PID;
	char	*message;
}	t_signal;

void	sigusr1_handler(int signum);
void	sigusr2_handler(int signum);
void	send_signal(int pid, char c);
int		ft_atoi(char *str);
void	aff_message(char *str);
int		ft_strlen(char *str);

#endif