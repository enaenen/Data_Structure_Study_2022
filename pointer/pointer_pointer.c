#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	*p[3] = { &a, &b, &c };
	int	**pptr = p;

	a = 10;
	b = 20;
	c = 30;

	printf("%d\n", *pptr[0]);
	printf("%d\n", **pptr);

	printf("%d\n", *(*(pptr + 1)));
	printf("%d\n", *(*(pptr + 2))+1);
}
