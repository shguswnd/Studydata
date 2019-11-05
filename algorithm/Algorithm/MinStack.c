#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
typedef struct Node {
	struct Node *before; //����
	int item; //������ �����Ͱ�
	int min; //�ּҰ��� ������ ����
}Node; //������

int size = 0; //�������

typedef struct Stack
{
	Node * top;
}Stack; //���û���


Node *getnode()
{
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	return node;
} //�ٳ��

void Init(Stack * stack)
{
	stack->top = NULL;
}//�ʱ�ȭ


void push(Stack *stack, int item) {

	Node *newnode = getnode();
	if (stack->top == NULL)//ó�� ���û����� ����
	{
		stack->top = getnode();
		stack->top->item = item;
		stack->top->before = NULL;
		size++;
		stack->top->min = item; //ó�������� �ּҰ��� ó�����̹Ƿ� ������ ����.
	}
	else {
		newnode = getnode();
		newnode->before = stack->top;
		newnode->item = item;
		//���ÿ���
		if (stack->top->min < item) //�ּҸ� ���Ͽ� new��忡 �ּҰ��κп� ���ǿ� ���� �ּҰ��� �־��־���.
			newnode->min = stack->top->min;
		else
			newnode->min = item;
		stack->top = newnode;
		size++;
	}
}
//push�� ���ý� ���ȿ� ����Ǵ°� , �����ּ�, �ּҰ� 3�����ִ°�.

void pushMilion(Stack *stack)
{
	for (int i = 0; i < 1000000; i++)
		push(stack, rand() % 9000 + 1000);
}//100������ ���������� 100���� push���ش�.

int pop(Stack *stack) {
	int data; //pop���� �����ͺ��� 
	Node *now = getnode();
	if (stack->top == NULL)//���� ������ ������ָ鼭 , ���� NULL����
	{
		printf("Stack Empty\n");
		return NULL;
	}
	else {
		now = stack->top->before;
		data = stack->top->item;
		free(stack->top);//pop���� �ʿ�����Ƿ� free
		stack->top = now;
		size--;//������ ����.
		return data;//������ ����
	}
}

void popMilion(Stack *stack)
{
	if (stack->top == NULL)//���� ������ ������ָ鼭 , ���� NULL����
	{
		printf("Stack Empty\n");
		return NULL;
	}
	for (int i = 0; i < 1000000; i++)//�鸸�� pop���ش�.
		pop(stack);
}
int findMin(Stack *stack)
{
	if (stack->top == NULL)//���� ������ ������ָ鼭 , ���� NULL����
	{
		printf("Stack Empty\n");
	}
	else
	{
		return stack->top->min;//������ �ּҰ� ����
	}
}


int main()
{
	char command; //��ɾ�
	int item; //�Է°�
	int data;//pop�����Ͱ�
	int min;//�ּҰ�
	Stack stack;//���û���


	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);


	srand(time(NULL));

	Init(&stack);//�ʱ�ȭ


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

			//��°� 
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("push %d (%d), cpu time= %.12f sec\n", item, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'P':
			QueryPerformanceCounter(&start);
			pushMilion(&stack);
			QueryPerformanceCounter(&end);

			//��°�
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("pushMilion (%d), cpu time= %.12f sec\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'o':
			QueryPerformanceCounter(&start);
			data = pop(&stack);
			QueryPerformanceCounter(&end);

			//��°�
			if (data != NULL)//pop�� NULL�ϰ��� pop�޼��忡�� ����ϹǷ� popNULL�� �ƴѰ�츸 ���⼭ ���.
			{
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("pop %d (%d), cpu time= %.12f sec\n", data, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			}
			break;
		case 'O':
			QueryPerformanceCounter(&start);
			popMilion(&stack);
			QueryPerformanceCounter(&end);

			//��°�
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("popMilion (%d), cpu time= %.12f sec\n", size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'f':
			QueryPerformanceCounter(&start);
			min = findMin(&stack);
			QueryPerformanceCounter(&end);

			//��°�
			if (min != NULL)//minp�� NULL�ϰ��� min�޼��忡�� ����ϹǷ� min NULL�� �ƴѰ�츸 ���⼭ ���.
			{
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("min %d (%d), cpu time= %.12f sec\n", min, size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			}
			break;
		case 'q'://���α׷� ����
			return;
			break;
		}
	}
}