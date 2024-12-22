#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb /10);
	char c = (nb % 10) + 48;
	write(1, &c, 1);
}

void	fizzbuzz(int nb)
{
	while (nb <= 100)
	{
		if (nb % 5 == 0 && nb % 3 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(nb);
		write(1, "\n", 1);
		nb++;
	}
}

int main()
{
	int nb;

	nb = 1;
	fizzbuzz(nb);
	return (0);
}