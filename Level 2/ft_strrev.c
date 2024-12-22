int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char    *ft_strrev(char *str)
{
	int len;
	int i;
	int tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[len];
		str[len] = str[i];
		str[i] = tmp;
		i++;
		len--;
	}
	return (str);
}
#include <stdio.h>
int main()
{
	char str[] = "salut";
	printf("%s\n", ft_strrev(str));
	return (0);
}