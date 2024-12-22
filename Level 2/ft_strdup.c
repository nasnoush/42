#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char    *ft_strdup(char *src)
{
	int	i;
	char *new;

	i = 0;
	new = malloc(ft_strlen(src) + 1);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
#include <stdio.h>
int main()
{
	char *s1 = "Salut";
	printf("%s\n", ft_strdup(s1));
	return (0);
}
