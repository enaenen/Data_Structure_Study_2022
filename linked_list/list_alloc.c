#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_single_list {
	struct s_single_list	*next;
	int			data;
}SingleList;

typedef struct s_head {
	SingleList	*pHead;
	int		count;
}ListHead;

SingleList	*allocNewNode(void)
{
	SingleList *newNode;

	newNode = (SingleList *)malloc(sizeof(SingleList));
	if (newNode == NULL)
	{
		printf("alloc error \n");
		exit (-1);
	}
	return (newNode);
}

SingleList	*findLastNode(ListHead *head)
{
	SingleList *current;

	if (head->pHead == NULL)
		return (NULL);
	current = head->pHead;
	while (current->next)
		current = current->next;
	return (current);
}


void	addElement(ListHead *head, int data)
{
	SingleList *newNode;
	SingleList *lastNode;

	newNode = allocNewNode();
	newNode->data = data;
	
	lastNode = findLastNode(head);
	if (lastNode == NULL)
		head->pHead = newNode;
	else
		lastNode->next = newNode;
	head->count++;
}
void	printElement(ListHead	*head)
{
	SingleList *list;

	list = head->pHead;
	for (int i = 0; i < head->count; i++)
	{
		printf(" %d ", list->data);
		list = list->next;
	}
}

int	main(void)
{
	ListHead listHead;
	
	listHead.pHead = NULL;
	listHead.count = 0;
	for (int i = 0; i < 10; i++)
		addElement(&listHead, i + 1);
	printElement(&listHead);
}
