int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	s;
	int count;

	i = 0;
	r = 0;
	s = 1;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			s = s * -1;
		}
		if (count == 1)
		{
			return (0);
		}
		count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * s);
}
#include <stdio.h>
int main()
{
	char *str = "   --7848";
	printf("%d\n", ft_atoi(str));
	return (0);
}