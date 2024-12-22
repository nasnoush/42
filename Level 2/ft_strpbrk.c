#include <stddef.h>
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				return ((char *)&s1[i]);
			}
			j++;
		}
		i++;
	}
	return NULL;
}

#include <stdio.h>

int main()
{
	char *s1 = "salut";
	char *s2 = "kadjku";

	char *result = ft_strpbrk(s1, s2);
	if (result)
		printf("First matching character: %c\n", *result);
	else
		printf("No matching characters found.\n");

	return (0);
}
