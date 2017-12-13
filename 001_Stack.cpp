/*
Stack은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조(LIFO - Last In First Out)로 데이터를 저장하는 형식을 말한다.  
주어진 N(2<= N <=100)개의 수를 순서대로 Stack에 넣은 후 하나씩 꺼내 화면에 출력하시오.

Input
2 // 테스트 케이스 수 
5 // 데이터 크기 
1 2 3 4 5
5
5 4 2 3 1

Output
#1 5 4 3 2 1 
#2 1 3 2 4 5
*/

#include <stdio.h>

#define MAX_N 100

int top;
int stack[MAX_N];

void stackInit(void)
{
	top = 0;
}

int stackIsEmpty(void)
{
	return (top == 0);
}

int stackIsFull(void)
{
	return (top == MAX_N);
}

int stackPush(int value)
{
	if (stackIsFull())
	{
		printf("stack overflow!");
		return 0;
	}
	stack[top] = value;
	top++;

	return 1;
}

int stackPop(int *value)
{
	if (top == 0) 
	{
		printf("stack is empty!");
		return 0;
	}
	top--;
	*value = stack[top];

	return 1;
}

int main(int argc, char* argv[])
{
	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		stackInit();
		for (int i = 0; i < N; i++) 
		{
			int value;
			scanf("%d", &value);
			stackPush(value);
		}

		printf("#%d ", test_case);

		while (!stackIsEmpty())
		{
			int value;
			if (stackPop(&value) == 1)
			{
				printf("%d ", value);
			}
		}
		printf("\n");
	}
	return 0;
}
