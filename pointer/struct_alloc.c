#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char	name[100];
	char	address[100];
	int	age;
}Person;

int	main(void)
{
	Person	**personArr;
	
	personArr = (Person **)malloc(sizeof(Person*) * 4);
	if (personArr == NULL)
	{
		printf("Alloc Error\n");
		exit(-1);
	}
	for (int i = 0; i < 3; i++)
	{
		personArr[i] = (Person*)malloc(sizeof(Person));
		if (personArr[i] == NULL) 
		{
			for (int j = 0; j < i; j++)
				free(personArr[j]);
			free(personArr);
			exit(-1);
		}

	}
	for (int i = 0; i < 3; i++)
	{
		printf("name (%d) : ", (i + 1));
		scanf("%s", personArr[i]->name);

		printf("address (%d) : ", (i + 1));
		scanf("%s", personArr[i]->address);
		
		printf("age (%d) : ", (i + 1));
		scanf("%d", &personArr[i]->age);
	}

	for (int i = 0; i < 3; i++)
		printf("%s %s %d \n", personArr[i]->name, personArr[i]->address, personArr[i]->age);
	for (int i = 0; i < 3; i++)
		free(personArr[i]);
	free(personArr);

}
