#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>

typedef struct Node {
	struct Node *next;
	int data;
}Node;// ���

typedef struct Queue {
	Node *front, *rear;
}Queue;//ť

typedef struct Stack {
	Queue *q1;
	Queue *q2;
}Stack;//������ �������.

Node* isEmpty(Queue *queue)
{
	return queue->front;
}//��尡 �ִ��� Ȯ����

Stack* Init() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->q1 = (Queue*)malloc(sizeof(Queue));
	stack->q2 = (Queue*)malloc(sizeof(Queue));
	stack->q1->front = NULL;
	stack->q1->rear = NULL;
	stack->q2->front = NULL;
	stack->q2->rear = NULL;
}//�ʱ�ȭ

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
}//���� �ִ� ť�� ������ش�.

int Delqueue(Queue *queue)
{
	int data = 0;
	Node *now;

	now = queue->front;
	data = now->data;
	queue->front = now->next;
	free(now);

	return data;
}//ť�� ����
void Push(Stack *stack, int *stackSize) {
	int data;
	while (1)//��ɾ�� ���͸� ������ ������ ť�� �������.
	{
		(*stackSize)++;
		scanf("%d", &data);
		EnQueue(stack->q1, data);
		if (getchar(data) == '\n')
			break;
	}
}//ť1�� push���ش�. ���⼭ EnQueue�޼���� ���� �־���.
void MillPush(Stack *stack, int data, int *stackSize)
{
	(*stackSize)++;
	EnQueue(stack->q1, data);
}//�������� �޾� ť�� ���� �־��ش�.
int Pop(Stack *stack, int *stackSize) {

	int PopData; //���� �����Ͱ�
	int Data;//pop��ɾ� ����  main �Լ��� �������� ��.

	if (stack->q1->front == stack->q1->rear)
	{
		*stackSize = 0;
		return Data = Delqueue(stack->q1);
	}//ť���� �ϳ��Ͻ� �ٷ� pop
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
	//ť1�� ť2�� �ű�� ������ ť1�� ���� �������ָ� �����ְ� ť2�� �ٽ� ť1���� �ű��.
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
}//ť1�ǰ����� ť2�� �ű�鼭 ������ ť1�� ���� top������ �����ϰ� ť2���� �ٽ� ť1���� �̵��Ͽ� ����.
int main() {
	int n, data, Top;
	int stackSize = 0;//������ ����� ��ɾ� ȣ��� ť���� ����Ͽ� ����� �����ϰ��Ѵ�.
	int PopData;
	char sw;//��ɾ�.

	Stack *stack = Init();//�ʱ�ȭ


	//�ð��Լ�
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);


	srand(time(NULL));


	while (1)
	{

		scanf("%c", &sw);
		if (!isEmpty(stack->q1))//��ɾ��� ������ �������� ������ ����� 0���� �ʱ�ȭ���ش�.
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