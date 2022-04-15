/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:01:15 by wchae             #+#    #+#             */
/*   Updated: 2022/04/10 15:11:43 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "single_linked_list.h"

int	addElement(ListNode data, int index)
{
	ListNode *new_node;
	ListNode *pre_node;

	if (0 <= index && index <= myList.count)
	{
		new_node = (ListNode *) malloc(sizeof(ListNode));
		if (new_node == NULL)
		{
			printf("Memory allocate error \n");
			exit(0);
		}
		new_node->data = data.data;
		new_node->pLink = data.pLink;
		pre_node = &(myList.pHead);
		for (int i = 0; i < index; i++)
			pre_node = pre_node->pLink;

		new_node->pLink = pre_node->pLink;
		pre_node->pLink = new_node;
		myList.count++;
	}
	else
	{
		printf("Not Avaliable Index \n");
		return -9999;
	}

}


int	removeElement(int index)
{
	ListNode	*del_node;
	ListNode	*pre_node;

	if (0 <= index && index <= myList.count)
	{
		del_node = &(myList.pHead);
		pre_node = del_node;

		for (int i = 0; i <= index; i++)
		{
			pre_node = del_node;
			del_node = del_node->pLink;
		}
		pre_node->pLink = del_node->pLink;
		myList.count--;

		free(del_node);
	}
	else
	{
		printf("Not Avaliable Index\n");
		return -9999;
	}
}
int	isEmpty()
{

}

void	printLinkedList()
{
	ListNode	*node;
	int		total;

	total = 0;
	node = &(myList.pHead);
	while (node->pLink != NULL)
	{
		node = node->pLink;
		printf("[%d] --> ", node->data);
		total += node->data;
	}
	printf("NULL \n");
	printf("total = %d\n", total);
}

int	main(void)
{
	myList.count = 0;
	myList.pHead.pLink = NULL;
	ListNode element;

	for (int i = 0; i < 5; i++)
	{
		element.data = i + 1;
		addElement(element, i);
	}
	printLinkedList();

	element.data = 10;
	addElement(element, 1);
	printLinkedList();

	removeElement(5);
	printLinkedList();

	removeElement(1);
	printLinkedList();
}
