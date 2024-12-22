void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
#include <stdio.h>
int main()
{
    int a = 5;
    int b = 2;

    printf("Before swap: a = %d, b = %d\n", a, b);

    ft_swap(&a, &b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}