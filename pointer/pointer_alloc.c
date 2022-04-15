#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	main()
{
	int	**arrPtr;

	arrPtr = (int **) malloc(sizeof(int *) * 10); 
	if (arrPtr == NULL)
	{
		printf("memory allocation error\n");
		exit(-1);
	}
	for (int i = 0; i < 10; i++)
	{
		arrPtr[i] = (int *)malloc(sizeof(int) * 10);
		memset(arrPtr[i], 0 , 40);

		if (arrPtr[i] == NULL)
		{
			for (int j = 0; j< i; j++)
				free(arrPtr[j]);
			free(arrPtr);
			exit(-1);
		}
	}
	int num = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			*(*(arrPtr + i) + j) = num++;
			printf("%d\t", *(*(arrPtr + i) + j));
		}
		printf("\n");
	}
	for (int i =0; i < 10; i++)
	{
		free(arrPtr[i]);
	}
	free(arrPtr);
}
