#include <stddef.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	i = 0;

	while(s[i])
	{
		if (s[i] == *reject)
		{
			break ;
		}
		i++;
	}
	return (i);
}

#include <stdio.h>
int main ()
{
	char *s = "salut";
	char *reject = "t";
	printf("%d\n", ft_strcspn(s, reject));
	return (0);

}