#include "polynomial.h"

void error(char *message)
{
	printf("%s", message);
	exit (1);	
}

LinkedList	*create() 
{
	LinkedList	*createdList;
	createdList = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!createdList)
		error("allocation Error\n");
	return createdList;
}

void    insert_last(LinkedList *pList, int coef, int expon)
{
	ListNode	*new = (ListNode *)malloc(sizeof(LinkedList));
	ListNode	*cur;
	if (!new)
		error("malloc error");
	new->coef = coef;
	new->expon = expon;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode = new;
		pList->tail = new;
	}
	else
	{
		pList->tail->pLink = new;
		pList->tail = new;
	}
	pList->currentElementCount++;
}

void    poly_add(LinkedList *pList1, LinkedList *pList2, LinkedList *pList3)
{
	ListNode *a = pList1->headerNode;
	ListNode *b = pList2->headerNode;

	int sum;
	sum = 0;
	while (a && b)
	{
		if (a->expon == b->expon)
		{
			sum = a->coef + a->coef;
			if (sum != 0)
				insert_last(pList3, sum, a->expon);
			a = a->pLink;
			b = b->pLink;
		}
		else if (a->expon > b->expon)
		{
			insert_last(pList3, a->coef, a->expon);
			a = a->pLink;
		}
		else 
		{
			insert_last(pList3, b->coef, b->expon);
			b = b->pLink;
		}
	}

	for (; a != NULL; a = a->pLink)
		insert_last(pList3, a->coef, a->expon);
	for (; b != NULL; b = b->pLink)
		insert_last(pList3, b->coef, b->expon);
}
void    poly_print(LinkedList *pList)
{
	ListNode *node = pList->headerNode;
	for(; node; node = node->pLink)
	{
		printf("%d^%d + ", node->coef, node->expon);
	}
	printf("\n");
}

int		main(void)
{
	LinkedList *list1, *list2, *list3;
	
	list1 = create();
	list2 = create();
	list3 = create();

		//3^12 + 2^8 + 1 
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	
	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
}
