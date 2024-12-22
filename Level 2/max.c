int		max(int* tab, unsigned int len)
{
	int i;
	int result;

	i = 0;
	result = tab[0];

	while (i < len)
	{
		if (tab[i] > result)
		{
			result = tab[i];
		}
		i++;
	}
	return (result);
}
#include <stdio.h>
int main()
{
	int tab[] = {5, 8, 58, 79, 2, 9, 6};
	int len = 7;

	printf("%d\n", max(tab, len));
	return (0);
}
