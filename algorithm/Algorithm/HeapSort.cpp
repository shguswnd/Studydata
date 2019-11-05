#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	struct treeNode *L_next;
	struct treeNode *R_next;
	struct treeNode *parent;
	int data;
}Tree; //트리노드 구성 좌우 자식과 부모를 연결할 포인트생성
Tree* getNode() {
	Tree *newNode = (Tree*)malloc(sizeof(Tree));
	newNode->L_next = NULL;
	newNode->R_next = NULL;
	newNode->data = NULL;
	newNode->parent = NULL;
	return newNode;
}//초기화 함수

typedef struct Node {
	struct Node *next;
	Tree* tree;
}Node; //큐를 활용한 트리를 연결할 노드 생성

typedef struct Queue {
	Node *rear, *front;
}Queue;//큐생성

Node* isEmpty(Queue *queue)
{
	return queue->front;
}//큐가 비었는지 판단.

Queue* getQueue()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}//큐 초기화


void EnQueue(Queue *queue, Tree* root)//큐생성
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->tree = root; //새로운노드에 트리주소삽입.
	newNode->next = NULL;

	if (!isEmpty(queue))
	{
		queue->rear = queue->front = newNode; //처음값 연결
	}
	else
	{
		queue->rear->next = newNode;//처음이후 연결
	}
	queue->rear = newNode; //마지막을 가르치는곳을 rear에 연결
}
Tree* Delqueue(Queue * queue) //큐 반환
{
	Node* Dummy;
	Tree* DummyTree;
	Dummy = queue->front;
	DummyTree = Dummy->tree;
	queue->front = Dummy->next;
	free(Dummy);
	return DummyTree; //더미 노드를 만들어 데이터연결을 변경후 반환 
	//리턴은 더미트리를 주어 지금 리턴되는 트리값을 리턴해줌
}

void swapElements(Tree *p, Tree* parent)
{
	int tmp;
	tmp = p->data;
	p->data = parent->data;
	parent->data = tmp;
	//트리의 데이터값 교환
}
void upHeap(Tree *p)
{
	Tree *parent = getNode();
	if (p->parent != NULL) //부모가 널이아닌 즉 루트일때 부모는 현 노드의 부모
		parent = p->parent;
	else if (p->parent == NULL) //루트이면 리턴
		return;
	if (p->data <= parent->data) //부모의값이 더크면 리턴
		return;
	swapElements(p, parent); //값 교환.
	upHeap(parent);//재귀업힙

}
void downheap(Tree* root)
{
	Tree* bigChild; //자식트리생성
	Tree *p = getNode();
	p = root;//루트저장
	if (p->L_next == NULL)//자식이 없는경우
		return;
	bigChild = p->L_next;
	if (p->R_next != NULL) //오른쪽이있을때
	{
		if (p->L_next->data <= p->R_next->data) //오른쪽 자식이 클때
			bigChild = p->R_next;
	}
	if (p->data >= bigChild->data)//자식보다 부모가 크면 그냥 리턴
		return;
	swapElements(bigChild, p); //교환
	downheap(bigChild); //재쉬 다운힙
}
Tree* advanceLast(Tree* last)
{
	Tree* parent = last->parent;//부모노드 저장 
	Tree* root = getNode();//루트트리생성
	if (parent == NULL) //부모가 널일때 마지막노드는 결국 루트다.
		root = last;
	if (root == last) //마지막노트가 루트이면.
	{
		last->L_next = getNode();
		last->L_next->parent = last;
		return last->L_next;//외쪽자식에 노드생성하고 노드를 리턴. 데이터삽입은 삽입함수에서 사용

	}
	while (1)
	{
		if (parent->R_next == last) //부모의 오른쪽자식이 마지막노드일때
		{
			last = last->parent; //부모로 마지막노드 이동
			if (last->parent == NULL) //여기서 노드의 부모가 널인 루트이면 
			{
				while (last->L_next != NULL) //왼쪽자식으로 계속 이동함.
				{
					last = last->L_next;
				}
				last->L_next = getNode();
				last->L_next->parent = last;
				return last->L_next; //왼쪽자식의 노드를 생성하고 리턴.

			}
			parent = last->parent; //만약 루트가 아니면 부모를 저장.
		}
		else if (parent->L_next == last) //부모의 왼쪽자식이 마지막노드랑 같다면 형제노드 판별 시작
		{
			if (parent->R_next == NULL)  // 부모의 오른쪽 자식이 널이면 
			{
				parent->R_next = getNode();
				parent->R_next->parent = parent;
				return parent->R_next; //부모의 오른쪽 즉 형제노드를 바로 생성후 리턴.
			}
			else // 만약 형제노드의 값이 널이 아니라 있다면 새로운 판별 시도
			{

				last = parent->R_next; //부모의오른쪽을 last노드에 저장.
				if (last->L_next == NULL) //만약 현재가르치는 노드의 왼쪽이 널이면 
				{
					last->L_next = getNode();
					last->L_next->parent = last;
					return last->L_next;//바로 새로운 노드생성후 리턴.
				}
				else//만약 가르치는 노드가 널이 아니라면
				{
					while (last->L_next != NULL) //왼쪽으로 쭉이동.
					{
						last = last->L_next;
					}
					last->L_next = getNode();
					last->L_next->parent = last;
					return last->L_next;//값 리턴
				}
			}
		}

	}

}

Tree* insertItem(int data, Tree *p)
{
	if (p->parent == NULL && p->data == NULL && (p->L_next == NULL && p->R_next == NULL))//초기 루트이면 값 저장후 리턴
	{
		p->data = data;
		return p;
	}

	p = advanceLast(p); //함수 호출
	p->data = data;//리턴받은 주소에 값 저장.
	upHeap(p);

	return p;//마지막 노드를 지정하기위하여 p리턴.


}
Tree* removemax(Tree* root, Tree* last)
{
	printf("%d\n", root->data); //제거되는 루트값을 일단출력함. free는 밑에서 해결.
	root->data = last->data;//루트데이터 값에 마지막 값 저장. 

	if (last->parent == NULL)//루트일때
	{
		free(last);//프리해주고
		root = getNode();//루트를 재생성
		return root;//재생성한 루트를 보내줌 이때 값 현상오류때문에 메인에서 루트주소를 바꿔주는것.
	}
	if (last->parent->L_next == last) //부모의왼쪽자식이 현재노드와 같다면
	{
		last->parent->L_next = NULL; //연결을 끊어주고
		free(last);//프리해줌.
	}
	else if (last->parent->R_next == last)//부모의 오른쪽자식이 현재노드와 같다면.
	{
		last->parent->R_next = NULL;//연결을 끊어주고
		free(last);//프리해줌.
	}


	downheap(root);//다운힙.

	//큐를 활용하여 마지막노드를 구별한다.
	Queue *queue = getQueue();
	Tree* data;
	EnQueue(queue, root);//큐와 루트를 보내줌.

	while (1)
	{
		data = Delqueue(queue);//처음에 루트부터라면 루트주소를 보내주며 왼쪽자식과 오른쪽자식을 다시 큐에 넣고 큐를 다시 삭제하면서 그 자식들의 왼쪽 오른쪽들을 큐에 다시저장.
		if (data->L_next != NULL)//자식이 존재할때만 큐에 저장.
			EnQueue(queue, data->L_next);
		if (data->R_next != NULL)
			EnQueue(queue, data->R_next);
		if (data->L_next == NULL && data->R_next == NULL)//자식이 더이상 없다면 종료
			break;
	}
	last = data;//현재 반복문에서 끝난 주소를 저장
	while (isEmpty(queue))//만약 큐의값이 아직 남아있다면 반환
	{
		data = Delqueue(queue);
		last = data;//반환된 트리주소 저장.
	}
	return last;//마지막주소를 리턴해줌.
}

void printHeap(Tree* root)
{
	Queue *queue = getQueue();
	Tree* data;

	EnQueue(queue, root);//큐를 사용한 출력
	while (1)
	{
		data = Delqueue(queue);//처음에 루트부터라면 루트주소를 보내주며 왼쪽자식과 오른쪽자식을 다시 큐에 넣고 큐를 다시 삭제하면서 그 자식들의 왼쪽 오른쪽들을 큐에 다시저장.
		printf(" %d", data->data);//출력
		if (data->L_next != NULL)
			EnQueue(queue, data->L_next);
		if (data->R_next != NULL)
			EnQueue(queue, data->R_next);
		if (data->L_next == NULL && data->R_next == NULL)
			break;//자식이 존재할떄까지 큐에 저장후 반복문 종료
	}
	while (isEmpty(queue))//큐가 존재할떄까지 출력.
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
	last = root;//주소 연결.

	while (1)
	{
		scanf("%c", &sel);


		if (sel == 'i')
		{
			scanf("%d", &data);

			last = insertItem(data, last); //삽입

			printf("0\n");
		}
		else if (sel == 'd')
		{
			if (root->data != NULL) //루트값이  있을 때만 삭제가능
				last = removemax(root, last);
			if (last->data == NULL)//마지막 노드가 널이면 즉 루트까지 간다면 마지막 노드를 루트로 초기화를 해줌 free때문에 데이터 손실되는걸 방지함.
				root = last;
		}
		else if (sel == 'p')
		{
			if (root->data != NULL)//트리가있을경우만 출력
				printHeap(root);

		}
		else if (sel == 'q')
			return;
	}
}