/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:03:27 by wchae             #+#    #+#             */
/*   Updated: 2022/04/17 11:42:12 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList	*createLinkedList()
{
	LinkedList	*linkedList;

	linkedList = (LinkedList *)malloc(sizeof(LinkedList));
	if (!linkedList)
	{
		printf("allocation failed\n");
		return (FALSE);
	}
	linkedList->currentElementCount = 0;
	return linkedList;
}

int	getLinkedListLength(LinkedList *pList)
{
	int	index;

	index = 0;
	ListNode *currentNode = pList->headerNode.pLink;
	while (currentNode)
	{
		index++;
		currentNode = currentNode->pLink;
	}
	return index;
}

int	addLLElement(LinkedList *pList, int position, ListNode element)
{
	int			index;
	ListNode	*prev;
	ListNode	*new;
	
	if (!pList || pList->currentElementCount < position || position < 0)
		return (FALSE);
	new = (ListNode *)malloc(sizeof(ListNode));
	if (!new)
		return (FALSE);
	*new = element;
	prev = &(pList->headerNode);
	index = 0;
	while (index++ < position)
		prev = prev->pLink;
	new->pLink = prev->pLink;
	prev->pLink = new;
	pList->currentElementCount++;
	return (TRUE);
}
int removeLLElement(LinkedList* pList, int position)
{
	ListNode *target;
	ListNode *prev;
	int	index;
	
	if (!pList || pList->currentElementCount <= position || position < 0)
		return (FALSE);
	index = 0;
	prev = &(pList->headerNode);
	while (index++ < position)
		prev = prev->pLink;
	target = prev->pLink;
	prev->pLink = target->pLink;
	pList->currentElementCount--;
	free(target);
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*target;
	int			index;

	if (!pList || pList->currentElementCount <= position || position < 0)
		return (FALSE);
	target = &(pList->headerNode);
	index = 0;
	while (index < position)
	{
		target = target->pLink;
		index++;
	}
	return (target);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode	*head;
	ListNode	*target;
	ListNode	*next;

	if (pList->currentElementCount == 0)
		return ;
	head = &(pList->headerNode);
	target = head->pLink;
	while (target)
	{
		next = target->pLink;
		free(target);
		target = next;
	}
	head->pLink = NULL;
	pList->currentElementCount = 0;
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList* pList)
{
	ListNode	*node;
	node = pList->headerNode.pLink;
	while (node)
	{
		printf(" %d ", node->data);
		node = node->pLink;
	}
}

int	main(void)
{
	LinkedList *pList = createLinkedList();
	ListNode element;
	
	pList = createLinkedList();
	element.data = 1;
	addLLElement(pList, 0, element);
	element.data = 2;
	addLLElement(pList, 1, element);
	element.data = 3;
	addLLElement(pList, 2, element);
	element.data = 4;
	addLLElement(pList, 3, element);
	displayAllLinkedList(pList);
	removeLLElement(pList, 2);
	printf("\n");
	displayAllLinkedList(pList);
	clearLinkedList(pList);
}
