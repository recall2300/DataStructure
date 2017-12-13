/*
Hash table은 키를 값에 매핑할 수 있는 구조인, 연관 배열 추가에 사용되는 자료 구조이다. 
Hash table은 Hash 함수를 사용하여 색인(index, Key)을 버킷(bucket)이나 슬롯(slot)의 배열로 계산한다.  
주어진 N개의 key, data쌍을 Hash table에 입력한 후, Q개의 key를 입력 받아 key에 해당하는 data를 각 줄에 출력하시오. 
(1<=N, Q<=4096) * Key : 최대 64개의 문자열 * Data : 최대 128개의 문자열

Input
2 // 테스트 케이스 수 T  
8 // 입력 데이터 수 N 
Attract Charm //key data 
Gather  Collect  
Fundamental Essential  
Abundant  Plentiful  
Achieve  Accomplish  
Assign  Allocate  
Surprise   Amaze   
Assess  Estimate   
3 // 검색할 데이터 수 Q 
Attract 
Surprise 
education 
10 
Bear Stand   
Famous Noted   
Characteristic Attribute   
Decrease Diminish   
Defect Flaw   
Depict Describe   
Eager Avid   
Flourish Thrive   
Huge  Tremendous   
Important  Crucial   
5  
treasure   
Bear  
Defect  
Huge  
hydrogen

Output
#1
Charm
Amaze
not find
#2
not find
Stand
Flaw
Tremendous
not find
*/

#include <stdio.h>
#include <string.h>
#include <memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096
 
typedef struct
{
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
}Hash;
Hash tb[MAX_TABLE];

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

int find(const char *key, char *data)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;
	int step = 1;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			strcpy(data,tb[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int add(const char *key, char *data)
{
	unsigned long h = hash(key);
	int step = 1;
	int i = 0;

	while (tb[h].key[0] != 0)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	strcpy(tb[h].data, data);
	return 1;
}


int main(int argc, char* argv[])
{
	int T, N, Q;
	
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(tb, 0, sizeof(tb));
		scanf("%d", &N);
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];

		for (int i = 0; i < N; i++)
		{
			scanf("%s %s\n", &k, &d);
			add(k,d);
		}

		printf("#%d\n", test_case);

		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];
			
			scanf("%s\n", &k);

			if (find(k,d))
			{
				printf("%s\n",d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
	return 0;
}
