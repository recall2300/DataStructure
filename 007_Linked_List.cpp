/*
Linked List는 각 노드가 데이터와 포인터를 가지고 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 자료 구조이다. 
주어진 N(2<= N <=100)개의 수를 순서대로 Linked List에 넣은 후, 
2개의 간격으로 하나씩 데이터를 뺄 때 마지막에 남아 있는 데이터를 출력하시오. 
Ex) 1 2 3 4 5 -> 2 3 4 5 -> 2 3 5 -> 2 5 -> 2

Input
2 //테스트 케이스 수 
5 //입력 수 
1 2 3 4 5 //입력 데이터 
6
1 2 3 4 5 6

Output
#1 2 
#2 5
*/

#include <stdio.h>

#define MAX_NODE 100

typedef struct listNode
{
	int data;
	struct listNode* prev;
	struct listNode* next;
} ListNode;

typedef struct
{
	int use;
	ListNode node;
} ListNodeHeap;

ListNodeHeap heap[MAX_NODE];
	
void initHeap(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		heap[i].use = 0;
	}
}

void initListNode(ListNode* node)
{
	node->data = 0;
	node->prev = node;
	node->next = node;
}

ListNode* getListNode(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		if (!heap[i].use)
		{
			heap[i].use = 1;
			initListNode(&heap[i].node);
			return &heap[i].node;
		}
	}
	return NULL;
}

void destroyListNode(ListNode* node)
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
}

ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();
	node->data = data;
	if (list == NULL)
	{
		return node;
	}
	else
	{
		ListNode* last = list->prev;
		last->next = node;
		list->prev = node;
		node->prev = last;
		node->next = list;
		return list;
	}
}

ListNode* removeListNode(ListNode* list, ListNode* node)
{
	if (list == list->next)
	{
		destroyListNode(node);
		return NULL;
	}
	else
	{
		ListNode* prev = node->prev;
		ListNode* next = node->next;
		prev->next = next;
		next->prev = prev;
		destroyListNode(node);
		return (list == node) ? next : list;
	}
}

int main(int argc, char* argv[])
{

	int T, N;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		ListNode* list = NULL;
		ListNode* node;
		int i;

		initHeap();

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			int data;
			scanf("%d", &data);
			list = appendListNode(list, data);
		}

		node = list;
		while (list != list->next)
		{
			ListNode* nextNode = node->next;
			list = removeListNode(list, node);
			node = nextNode->next->next;
		}

		printf("#%d %d\n", test_case, list->data);
	}
	return 0;
}
