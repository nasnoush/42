int    ft_strcmp(char *s1, char *s2)
{
	int	i;
	i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1 - s2);
}
#include <stdio.h>
int main()
{
	char *s1 = "Salut";
	char *s2 = "SaLut";
	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}