#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

# define BUFFER_SIZE 1
# define SIGUSR1 10
# define SIGUSR2 12

typedef struct s_signal
{
	int		PID;
	char	*message;
}	t_signal;

void	sigusr1_handler(int signum);
void	sigusr2_handler(int signum);
void	send_signal(int pid, char c);
int		ft_atoi(char *str);
int		ft_strlen(char *str);

#endif