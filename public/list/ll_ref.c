#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList *createLinkedList(void)
{
    LinkedList *new;
    new = calloc(1, sizeof(LinkedList));
    if (!new)
        return (NULL);
    return (new);
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
    ListNode *new; // 추가하려는 노드
    ListNode *prev; // 추가하려는 노드를 연결 할 이전 노드

    if(!pList || position < 0 || position > pList->currentElementCount) // 에러 처리
        return (FALSE);
    new = malloc(sizeof(ListNode) * 1); // 새 노드 할당
    if (!new)
        return (FALSE);
    *new = element; // 역참조를 통해 추가하려는 원소의 모든 정보 저장
    prev = &(pList->headerNode); // headerNode라는 더미노드를 통해 연결
    for (int i = 0; i < position; i++) // 추가하려는 position '전' 까지 prev 이동
        prev = prev->pLink;
    new->pLink = prev->pLink; // 추가하려는 노드의 pLink에 이전 노드의 pLink를 연결
    prev->pLink = new; // 이전 노드의 pLink를 추가하려는 노드에 연결
    // 위 두 과정의 순서가 바뀔 시 이전 노드의 pLink를 잃게 되므로 순서 중요
    pList->currentElementCount++; // 현재 원소 개수 갱신
    return (TRUE);
}int removeLLElement(LinkedList* pList, int position)
{
    ListNode *remove; // 지우려는 노드
    ListNode *prev; // 이전 노드

    if (!pList || position < 0 || position >= pList->currentElementCount) // 에러 처리
        return (FALSE);
    prev = &(pList->headerNode); // 더미노드를 초기 노드로 설정하여 pLink를 통해 실제 첫 원소부터 탐색
    for (int i = 0; i < position; i++) // 지우려는 position까지 '전' 까지 prev 이동
        prev = prev->pLink;
    remove = prev->pLink; // 지울 노드의 할당 해제를 위해 remove 변수에 저장
    prev->pLink = remove->pLink; // 이전 노드의 pLink를 지울 노드의 pLink로 연결 
    pList->currentElementCount--; // 현재 원소 개수 갱신
    free(remove); // 할당 해제
    return (TRUE);
}

ListNode *getLLElement(LinkedList *pList, int position)
{
    ListNode *ret;

    if (!pList || position < 0 || position >= pList->currentElementCount) // 에러 처리
        return (FALSE);
    ret = &(pList->headerNode); // 더미노드
    for (int i = 0; i <= position; i++) // position까지 이동
        ret = ret->pLink;
    return (ret); // 해당 노드 반환
}

void reverseList(LinkedList *pList)
{
    ListNode *first;
    ListNode *cur;
    ListNode *last;

    if (!pList)
        return ;
    first = pList->headerNode.pLink; // 실제 첫 원소로 초기화 (cur보다 하나 앞으로 이동)
    cur = NULL; // NULL로 초기화 (현재 리스트의 첫 시작 노드가 마지막 노드가 되어 headerNode가 아닌 NULL을 가리킬 수 있도록)
    while (first) // first가 마지막 노드의 다음으로 이동해 NULL이 되면  while문 종료
    {
        last = cur; // cur의 pLink를 이전 노드로 연결하여 역방향을 만들 수 있도록 last를 cur 노드 위치로 이동
        cur = first; // 연결 방향을 바꿀 수 있도록 cur 다음 노드인 first 노드로 이동
        first = cur->pLink; // 다음 반복문에서 cur가 이동할 수 있도록 first 
        cur->pLink = last; // cur의 pLink를 전 노드에 머물고 있는 last에 연결하여 연결 방향 변경
    }
    pList->headerNode.pLink = cur; // 리스트를 전부 순회화며 역방향 조정이 끝나면 원 리스트의 마지막 노드가 첫 시작 노드가 될 수 있도록 headerNode의 pLink를 cur에 연결
}

int getLinkedListLength(LinkedList *pList)
{
    return (pList->currentElementCount);
}

void displayLinkedList(LinkedList *pList)
{
    ListNode	*cur;
    int         i;    

    if (!pList)
    {
        printf("No List\n"); // 에러 처리
        return ;
    }
    printf("(1) Current Element count: %d\n", pList->currentElementCount);
    if (pList->currentElementCount == 0)
        printf("(2) Element: No Element");
    else
        printf("(2) Element: ");
    cur = pList->headerNode.pLink;
    i = 0;
    while (cur) // 리스트 노드 순회
    {
        printf("[%d]: %d", i++, cur->data);
        if (i != pList->currentElementCount)
            printf(", "); // 마지막 노드 제외 쉼표 출력
        cur = cur->pLink;
    }
    printf("\n");
}

void clearLinkedList(LinkedList* pList)
{
    ListNode* headerNode;
    ListNode* node;
    ListNode* temp;

    if (pList->currentElementCount == 0)
        return ;
    headerNode = &(pList->headerNode); // 더미노드
    node = headerNode->pLink; // 첫 노드
    while (node) // 노드가 마지막 노드 이후 NULL이 되면 while문 종료
    {
        temp = node->pLink; // 현재 노드의 다음 노드 저장을 위한 임시 변수 설정
        free(node); // 현재 노드 할당 해제
        node = temp; // 이전에 저장해 놓은 임시 변수 값을 가져와 연속적으로 리스트 순회
    }
    headerNode->pLink = NULL; // 할당 해제 된 메모리에 접근할 수 없도록 NULL 처리
    pList->currentElementCount = 0; // 현재 원소 개수 초기화
}

void deleteLinkedList(LinkedList *pList)
{
    clearLinkedList(pList); // clear를 통해 리스트 내부 모든 노드 할당 해제
    free(pList); // 리스트 구조체 할당 해제
}


int main(void)
{
    LinkedList	*pList;
    ListNode	*node;
    ListNode	element;
    int			loop;
    int			opt;
	int			position;

	pList = createLinkedList();
	element.data = 1;
	addLLElement(pList, 0, element);
		element.data = 3;
	addLLElement(pList, 1, element);
		element.data = 2;
	addLLElement(pList, 2, element);
	displayLinkedList(pList);
	removeLLElement(pList,3);
	displayLinkedList(pList);
	removeLLElement(pList,2);
	displayLinkedList(pList);



}