#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

# include <stdio.h>
# include <stdlib.h>

typedef struct ListNodeType {
    int coef;
    int expon;// 지수
    struct ListNodeType *pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode *headerNode;
    ListNode *tail;
} LinkedList;

void error(char *message);
LinkedList *create();
void    insert_last(LinkedList *pList, int coef, int expon);
void    poly_add(LinkedList *pList1, LinkedList *pList2, LinkedList *pList3);
void    poly_print(LinkedList *pList);

# define FALSE 0
# define TRUE 1

#endif