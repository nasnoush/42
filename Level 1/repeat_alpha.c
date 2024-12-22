#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int repeat;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			repeat = str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			repeat = str[i] - 'A' + 1;
		else
			repeat = 1;
		while (repeat > 0)
		{
			write(1, &str[i], 1);
			repeat--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}