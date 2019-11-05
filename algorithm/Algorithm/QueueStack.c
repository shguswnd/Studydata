#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>

typedef struct Node {
	struct Node *next;
	int data;
}Node;// 노드

typedef struct Queue {
	Node *front, *rear;
}Queue;//큐

typedef struct Stack {
	Queue *q1;
	Queue *q2;
}Stack;//스택을 만들어줌.

Node* isEmpty(Queue *queue)
{
	return queue->front;
}//노드가 있는지 확인함

Stack* Init() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->q1 = (Queue*)malloc(sizeof(Queue));
	stack->q2 = (Queue*)malloc(sizeof(Queue));
	stack->q1->front = NULL;
	stack->q1->rear = NULL;
	stack->q2->front = NULL;
	stack->q2->rear = NULL;
}//초기화

void EnQueue(Queue *queue, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (!isEmpty(queue))
	{
		queue->rear = queue->front = newNode;
	}
	else {
		queue->rear->next = newNode;
	}
	queue->rear = newNode;
}//값을 넣는 큐를 만들어준다.

int Delqueue(Queue *queue)
{
	int data = 0;
	Node *now;

	now = queue->front;
	data = now->data;
	queue->front = now->next;
	free(now);

	return data;
}//큐값 삭제
void Push(Stack *stack, int *stackSize) {
	int data;
	while (1)//명령어시 엔터를 누르기 전까지 큐를 만들어줌.
	{
		(*stackSize)++;
		scanf("%d", &data);
		EnQueue(stack->q1, data);
		if (getchar(data) == '\n')
			break;
	}
}//큐1을 push해준다. 여기서 EnQueue메서드로 값을 넣어줌.
void MillPush(Stack *stack, int data, int *stackSize)
{
	(*stackSize)++;
	EnQueue(stack->q1, data);
}//랜덤값을 받아 큐에 값을 넣어준다.
int Pop(Stack *stack, int *stackSize) {

	int PopData; //팝한 데이터값
	int Data;//pop명령어 에서  main 함수에 리턴해줄 값.

	if (stack->q1->front == stack->q1->rear)
	{
		*stackSize = 0;
		return Data = Delqueue(stack->q1);
	}//큐값이 하나일시 바로 pop
	else
	{
		while (stack->q1->front != stack->q1->rear)
		{
			PopData = Delqueue(stack->q1);
			EnQueue(stack->q2, PopData);
		}
		Data = Delqueue(stack->q1);
		while (stack->q2->front)
		{

			PopData = Delqueue(stack->q2);
			EnQueue(stack->q1, PopData);
		}
	}
	(*stackSize)--;
	return Data;
	//큐1을 큐2로 옮기고 마지막 큐1의 값을 리턴해주며 팝해주고 큐2를 다시 큐1으로 옮긴다.
}
int top(Stack *stack)
{
	int TopData;
	int Data;
	if (stack->q1->front == stack->q1->rear)
		return stack->q1->front->data;
	else
	{
		while (stack->q1->front != stack->q1->rear)
		{
			Data = Delqueue(stack->q1);
			EnQueue(stack->q2, Data);
		}
		TopData = Delqueue(stack->q1);
		Data = TopData;
		EnQueue(stack->q2, Data);
		while (stack->q2->front)
		{
			Data = Delqueue(stack->q2);
			EnQueue(stack->q1, Data);
		}
	}
	return TopData;
}//큐1의값들을 큐2로 옮기면서 마지막 큐1의 값을 top값으로 저장하고 큐2값을 다시 큐1으로 이동하여 저장.
int main() {
	int n, data, Top;
	int stackSize = 0;//스택의 사이즈를 명령어 호출시 큐들을 사용하여 사이즈를 구분하게한다.
	int PopData;
	char sw;//명령어.

	Stack *stack = Init();//초기화


	//시간함수
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);


	srand(time(NULL));


	while (1)
	{

		scanf("%c", &sw);
		if (!isEmpty(stack->q1))//명령어전 스택이 비었을경우 스택의 사이즈를 0으로 초기화해준다.
			stackSize = 0;
		if (sw == 'S') {
			QueryPerformanceCounter(&start);

			if (!isEmpty(stack->q1))
				printf("Empty (%d), ", stackSize);
			else
				printf("Nonempty(%d), ", stackSize);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cpu time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		}
		else if (sw == 'p') {
			QueryPerformanceCounter(&start);

			Push(stack, &stackSize);
			printf("OK (%d), ", stackSize);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cpu time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		}
		else if (sw == 'P')
		{
			QueryPerformanceCounter(&start);
			for (int i = 0; i < 1000000; i++)
			{
				MillPush(stack, rand() % 90 + 10, &stackSize);
			}
			printf("OK (%d), ", stackSize);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cpu time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}
		else if (sw == 'o') {
			QueryPerformanceCounter(&start);

			if (!isEmpty(stack->q1))
			{
				printf("Empty Stack Exception!!(%d), ", stackSize);
			}
			else
			{
				PopData = Pop(stack, &stackSize);
				printf("%d (%d), ", PopData, stackSize);
			}

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cpu time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}
		else if (sw == 't')
		{
			QueryPerformanceCounter(&start);
			if (!isEmpty(stack->q1))
			{
				printf("Empty Stack Exception!!(%d), ", stackSize);
			}
			else
			{
				Top = top(stack);
				printf("%d (%d), ", Top, stackSize);
			}

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cpu time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}

		else if (sw == 'q')
			exit(0);

	}

}