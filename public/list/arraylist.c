/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:23:26 by wchae             #+#    #+#             */
/*   Updated: 2022/04/17 17:50:59 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList	*array_list;

	array_list = (ArrayList *)malloc(sizeof(ArrayList));
	if (!array_list)
		return (NULL);
	array_list->maxElementCount = maxElementCount;
	array_list->currentElementCount = 0;
	array_list->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!array_list->pElement)
	{
		free(array_list);
		return (NULL);
	}
	return (array_list);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList || pList->maxElementCount <= 0)
		return;
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	return (pList->currentElementCount == pList->maxElementCount);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	ArrayListNode	*new;
	int				index;
	if (!pList || position < 0 || pList->currentElementCount < position)
		return (FALSE);
	if (isArrayListFull(pList))
	{
		new = (ArrayListNode *)malloc(sizeof(ArrayListNode) * pList->maxElementCount * 2);
		if (!new)
			return (FALSE);
		index = 0;
		while (index < pList->currentElementCount)
		{
			new[index] = pList->pElement[index];
			index++;
		}
		free(pList->pElement);
		pList->pElement = new;
		pList->maxElementCount *= 2;
	}
	index = pList->currentElementCount++;
	while (position < index)
	{
		pList->pElement[index] = pList->pElement[index - 1];
		index--;
	}
    pList->pElement[index] = element;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	int	index;

	if (!pList || pList->currentElementCount == 0 || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	pList->currentElementCount--;
	index = position;
	//만약 currentElementCount(맨 뒤 원소를 제거했다면?)
	//실제론 pElement 는 남아있지만 current를 줄인다. 
	//-> 할당해제하는게 아니기때문에 의미가 없다.
	while (index < pList->currentElementCount)
	{
		pList->pElement[index] = pList->pElement[index + 1];
		index++;
	}	
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (!pList || pList->currentElementCount == 0 || position == 0 || pList->currentElementCount <= position)
		return (FALSE);
	return (&pList->pElement[position]);
}

void displayArrayList(ArrayList* pList)
{
	int	index;

	if (!pList)
	{
		printf("No Array \n");
		return ;
	}
	if (!pList->currentElementCount)
		printf("No Element \n");
	else
	{
		index = 0;
		while (index < pList->currentElementCount)
			printf("[%d] %d \n", index ,pList->pElement[index++].data);
	}
}
void clearArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	pList->currentElementCount = 0;
}
int getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}

int	main(void)
{
	ArrayList *list = createArrayList(10);

	for (int i = 0; i < 10; i++){
		ArrayListNode node;
		node.data = i;
		addALElement(list, i, node);
	}
	displayArrayList(list);
}
