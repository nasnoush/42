#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		while (s1[i] == s2[j] && (s1[i] && s2[j]))
		{
			i++;
			j++;
		}
		j++;
	}
	if (s1[i] == '\0')
	{
		i = 0;
		while (s1[i])
		{
			write(1, &s1[i], 1);
			i++;
		}
	}
}

int main (int argc, char  **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}