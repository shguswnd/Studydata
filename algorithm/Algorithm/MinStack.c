#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
typedef struct Node {
	struct Node *before; //연결
	int item; //저장할 데이터값
	int min; //최소값을 저장할 변수
}Node; //노드생성

int size = 0; //사이즈변수

typedef struct Stack
{
	Node * top;
}Stack; //스택생성


Node *getnode()
{
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	return node;
} //겟노드

void Init(Stack * stack)
{
	stack->top = NULL;
}//초기화


void push(Stack *stack, int item) {

	Node *newnode = getnode();
	if (stack->top == NULL)//처음 스택생성시 조건
	{
		stack->top = getnode();
		stack->top->item = item;
		stack->top->before = NULL;
		size++;
		stack->top->min = item; //처음값에는 최소값이 처음것이므로 조건이 없음.
	}
	else {
		newnode = getnode();
		newnode->before = stack->top;
		newnode->item = item;
		//스택연결
		if (stack->top->min < item) //최소를 비교하여 new노드에 최소값부분에 조건에 따라 최소값을 넣어주었다.
			newnode->min = stack->top->min;
		else
			newnode->min = item;
		stack->top = newnode;
		size++;
	}
}
//push에 스택시 노드안에 저장되는값 , 연결주소, 최소값 3개가있는것.

void pushMilion(Stack *stack)
{
	for (int i = 0; i < 1000000; i++)
		push(stack, rand() % 9000 + 1000);
}//100만개의 랜덤값들을 100만번 push해준다.

int pop(Stack *stack) {
	int data; //pop해줄 데이터변수 
	Node *now = getnode();
	if (stack->top == NULL)//값이 없을시 출력해주면서 , 리턴 NULL해줌
	{
		printf("Stack Empty\n");
		return NULL;
	}
	else {
		now = stack->top->before;
		data = stack->top->item;
		free(stack->top);//pop으로 필요없으므로 free
		stack->top = now;
		size--;//사이즈 낮춤.
		return data;//데이터 리턴
	}
}

void popMilion(Stack *stack)
{
	if (stack->top == NULL)//값이 없을시 출력해주면서 , 리턴 NULL해줌
	{
		printf("Stack Empty\n");
		return NULL;
	}
	for (int i = 0; i < 1000000; i++)//백만번 pop해준다.
		pop(stack);
}
int findMin(Stack *stack)
{
	if (stack->top == NULL)//값이 없을시 출력해주면서 , 리턴 NULL해줌
	{
		printf("Stack Empty\n");
	}
	else
	{
		return stack->top->min;//스택의 최소값 리턴
	}
}


int main()
{
	char command; //명령어
	int item; //입력값
	int data;//pop데이터값
	int min;//최소값
	Stack stack;//스택생성


	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);


	srand(time(NULL));

	Init(&stack);//초기화


	while (1)
	{

		scanf("%c", &command);
		switch (command)
		{
		case 'p':
			scanf("%d", &item);
			QueryPerformanceCounter(&start);
			push(&stack, item);
			QueryPerformanceCounter(&end);

			//출력값 
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("push %d (%d), cpu time= %.12f sec\n", item, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'P':
			QueryPerformanceCounter(&start);
			pushMilion(&stack);
			QueryPerformanceCounter(&end);

			//출력값
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("pushMilion (%d), cpu time= %.12f sec\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'o':
			QueryPerformanceCounter(&start);
			data = pop(&stack);
			QueryPerformanceCounter(&end);

			//출력값
			if (data != NULL)//pop이 NULL일경우는 pop메서드에서 출력하므로 popNULL이 아닌경우만 여기서 출력.
			{
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("pop %d (%d), cpu time= %.12f sec\n", data, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			}
			break;
		case 'O':
			QueryPerformanceCounter(&start);
			popMilion(&stack);
			QueryPerformanceCounter(&end);

			//출력값
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("popMilion (%d), cpu time= %.12f sec\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'f':
			QueryPerformanceCounter(&start);
			min = findMin(&stack);
			QueryPerformanceCounter(&end);

			//출력값
			if (min != NULL)//minp이 NULL일경우는 min메서드에서 출력하므로 min NULL이 아닌경우만 여기서 출력.
			{
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("min %d (%d), cpu time= %.12f sec\n", min, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			}
			break;
		case 'q'://프로그램 종료
			return;
			break;
		}
	}
}