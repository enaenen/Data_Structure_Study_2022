#ifndef SINGLE_LINKED_LIST_H
# define SINGLE_LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	listNode
{
	int			data;
	struct listNode*	pLink;
}ListNode;

typedef struct	singleListType
{
	ListNode	pHead;
	int		count;
}SingleListType;

SingleListType	myList;

int	addElement(ListNode data, int index);
int	removeElement(int index);
int	isEmpty();
void	printLinkedList();

#endif
