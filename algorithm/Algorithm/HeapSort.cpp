#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	struct treeNode *L_next;
	struct treeNode *R_next;
	struct treeNode *parent;
	int data;
}Tree; //Ʈ����� ���� �¿� �ڽİ� �θ� ������ ����Ʈ����
Tree* getNode() {
	Tree *newNode = (Tree*)malloc(sizeof(Tree));
	newNode->L_next = NULL;
	newNode->R_next = NULL;
	newNode->data = NULL;
	newNode->parent = NULL;
	return newNode;
}//�ʱ�ȭ �Լ�

typedef struct Node {
	struct Node *next;
	Tree* tree;
}Node; //ť�� Ȱ���� Ʈ���� ������ ��� ����

typedef struct Queue {
	Node *rear, *front;
}Queue;//ť����

Node* isEmpty(Queue *queue)
{
	return queue->front;
}//ť�� ������� �Ǵ�.

Queue* getQueue()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}//ť �ʱ�ȭ


void EnQueue(Queue *queue, Tree* root)//ť����
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->tree = root; //���ο��忡 Ʈ���ּһ���.
	newNode->next = NULL;

	if (!isEmpty(queue))
	{
		queue->rear = queue->front = newNode; //ó���� ����
	}
	else
	{
		queue->rear->next = newNode;//ó������ ����
	}
	queue->rear = newNode; //�������� ����ġ�°��� rear�� ����
}
Tree* Delqueue(Queue * queue) //ť ��ȯ
{
	Node* Dummy;
	Tree* DummyTree;
	Dummy = queue->front;
	DummyTree = Dummy->tree;
	queue->front = Dummy->next;
	free(Dummy);
	return DummyTree; //���� ��带 ����� �����Ϳ����� ������ ��ȯ 
	//������ ����Ʈ���� �־� ���� ���ϵǴ� Ʈ������ ��������
}

void swapElements(Tree *p, Tree* parent)
{
	int tmp;
	tmp = p->data;
	p->data = parent->data;
	parent->data = tmp;
	//Ʈ���� �����Ͱ� ��ȯ
}
void upHeap(Tree *p)
{
	Tree *parent = getNode();
	if (p->parent != NULL) //�θ� ���̾ƴ� �� ��Ʈ�϶� �θ�� �� ����� �θ�
		parent = p->parent;
	else if (p->parent == NULL) //��Ʈ�̸� ����
		return;
	if (p->data <= parent->data) //�θ��ǰ��� ��ũ�� ����
		return;
	swapElements(p, parent); //�� ��ȯ.
	upHeap(parent);//��;���

}
void downheap(Tree* root)
{
	Tree* bigChild; //�ڽ�Ʈ������
	Tree *p = getNode();
	p = root;//��Ʈ����
	if (p->L_next == NULL)//�ڽ��� ���°��
		return;
	bigChild = p->L_next;
	if (p->R_next != NULL) //��������������
	{
		if (p->L_next->data <= p->R_next->data) //������ �ڽ��� Ŭ��
			bigChild = p->R_next;
	}
	if (p->data >= bigChild->data)//�ڽĺ��� �θ� ũ�� �׳� ����
		return;
	swapElements(bigChild, p); //��ȯ
	downheap(bigChild); //�罬 �ٿ���
}
Tree* advanceLast(Tree* last)
{
	Tree* parent = last->parent;//�θ��� ���� 
	Tree* root = getNode();//��ƮƮ������
	if (parent == NULL) //�θ� ���϶� ���������� �ᱹ ��Ʈ��.
		root = last;
	if (root == last) //��������Ʈ�� ��Ʈ�̸�.
	{
		last->L_next = getNode();
		last->L_next->parent = last;
		return last->L_next;//�����ڽĿ� �������ϰ� ��带 ����. �����ͻ����� �����Լ����� ���

	}
	while (1)
	{
		if (parent->R_next == last) //�θ��� �������ڽ��� ����������϶�
		{
			last = last->parent; //�θ�� ��������� �̵�
			if (last->parent == NULL) //���⼭ ����� �θ� ���� ��Ʈ�̸� 
			{
				while (last->L_next != NULL) //�����ڽ����� ��� �̵���.
				{
					last = last->L_next;
				}
				last->L_next = getNode();
				last->L_next->parent = last;
				return last->L_next; //�����ڽ��� ��带 �����ϰ� ����.

			}
			parent = last->parent; //���� ��Ʈ�� �ƴϸ� �θ� ����.
		}
		else if (parent->L_next == last) //�θ��� �����ڽ��� ���������� ���ٸ� ������� �Ǻ� ����
		{
			if (parent->R_next == NULL)  // �θ��� ������ �ڽ��� ���̸� 
			{
				parent->R_next = getNode();
				parent->R_next->parent = parent;
				return parent->R_next; //�θ��� ������ �� ������带 �ٷ� ������ ����.
			}
			else // ���� ��������� ���� ���� �ƴ϶� �ִٸ� ���ο� �Ǻ� �õ�
			{

				last = parent->R_next; //�θ��ǿ������� last��忡 ����.
				if (last->L_next == NULL) //���� ���簡��ġ�� ����� ������ ���̸� 
				{
					last->L_next = getNode();
					last->L_next->parent = last;
					return last->L_next;//�ٷ� ���ο� �������� ����.
				}
				else//���� ����ġ�� ��尡 ���� �ƴ϶��
				{
					while (last->L_next != NULL) //�������� ���̵�.
					{
						last = last->L_next;
					}
					last->L_next = getNode();
					last->L_next->parent = last;
					return last->L_next;//�� ����
				}
			}
		}

	}

}

Tree* insertItem(int data, Tree *p)
{
	if (p->parent == NULL && p->data == NULL && (p->L_next == NULL && p->R_next == NULL))//�ʱ� ��Ʈ�̸� �� ������ ����
	{
		p->data = data;
		return p;
	}

	p = advanceLast(p); //�Լ� ȣ��
	p->data = data;//���Ϲ��� �ּҿ� �� ����.
	upHeap(p);

	return p;//������ ��带 �����ϱ����Ͽ� p����.


}
Tree* removemax(Tree* root, Tree* last)
{
	printf("%d\n", root->data); //���ŵǴ� ��Ʈ���� �ϴ������. free�� �ؿ��� �ذ�.
	root->data = last->data;//��Ʈ������ ���� ������ �� ����. 

	if (last->parent == NULL)//��Ʈ�϶�
	{
		free(last);//�������ְ�
		root = getNode();//��Ʈ�� �����
		return root;//������� ��Ʈ�� ������ �̶� �� ������������� ���ο��� ��Ʈ�ּҸ� �ٲ��ִ°�.
	}
	if (last->parent->L_next == last) //�θ��ǿ����ڽ��� ������� ���ٸ�
	{
		last->parent->L_next = NULL; //������ �����ְ�
		free(last);//��������.
	}
	else if (last->parent->R_next == last)//�θ��� �������ڽ��� ������� ���ٸ�.
	{
		last->parent->R_next = NULL;//������ �����ְ�
		free(last);//��������.
	}


	downheap(root);//�ٿ���.

	//ť�� Ȱ���Ͽ� ��������带 �����Ѵ�.
	Queue *queue = getQueue();
	Tree* data;
	EnQueue(queue, root);//ť�� ��Ʈ�� ������.

	while (1)
	{
		data = Delqueue(queue);//ó���� ��Ʈ���Ͷ�� ��Ʈ�ּҸ� �����ָ� �����ڽİ� �������ڽ��� �ٽ� ť�� �ְ� ť�� �ٽ� �����ϸ鼭 �� �ڽĵ��� ���� �����ʵ��� ť�� �ٽ�����.
		if (data->L_next != NULL)//�ڽ��� �����Ҷ��� ť�� ����.
			EnQueue(queue, data->L_next);
		if (data->R_next != NULL)
			EnQueue(queue, data->R_next);
		if (data->L_next == NULL && data->R_next == NULL)//�ڽ��� ���̻� ���ٸ� ����
			break;
	}
	last = data;//���� �ݺ������� ���� �ּҸ� ����
	while (isEmpty(queue))//���� ť�ǰ��� ���� �����ִٸ� ��ȯ
	{
		data = Delqueue(queue);
		last = data;//��ȯ�� Ʈ���ּ� ����.
	}
	return last;//�������ּҸ� ��������.
}

void printHeap(Tree* root)
{
	Queue *queue = getQueue();
	Tree* data;

	EnQueue(queue, root);//ť�� ����� ���
	while (1)
	{
		data = Delqueue(queue);//ó���� ��Ʈ���Ͷ�� ��Ʈ�ּҸ� �����ָ� �����ڽİ� �������ڽ��� �ٽ� ť�� �ְ� ť�� �ٽ� �����ϸ鼭 �� �ڽĵ��� ���� �����ʵ��� ť�� �ٽ�����.
		printf(" %d", data->data);//���
		if (data->L_next != NULL)
			EnQueue(queue, data->L_next);
		if (data->R_next != NULL)
			EnQueue(queue, data->R_next);
		if (data->L_next == NULL && data->R_next == NULL)
			break;//�ڽ��� �����ҋ����� ť�� ������ �ݺ��� ����
	}
	while (isEmpty(queue))//ť�� �����ҋ����� ���.
	{
		data = Delqueue(queue);
		printf(" %d", data->data);
	}
	printf("\n");

}
void main()
{
	int data;
	char sel;

	Tree *root = getNode();
	Tree *last = getNode();
	last = root;//�ּ� ����.

	while (1)
	{
		scanf("%c", &sel);


		if (sel == 'i')
		{
			scanf("%d", &data);

			last = insertItem(data, last); //����

			printf("0\n");
		}
		else if (sel == 'd')
		{
			if (root->data != NULL) //��Ʈ����  ���� ���� ��������
				last = removemax(root, last);
			if (last->data == NULL)//������ ��尡 ���̸� �� ��Ʈ���� ���ٸ� ������ ��带 ��Ʈ�� �ʱ�ȭ�� ���� free������ ������ �սǵǴ°� ������.
				root = last;
		}
		else if (sel == 'p')
		{
			if (root->data != NULL)//Ʈ����������츸 ���
				printHeap(root);

		}
		else if (sel == 'q')
			return;
	}
}