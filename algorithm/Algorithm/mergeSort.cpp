#include<stdio.h>
#include<stdlib.h>
typedef struct node {//노드
	int data;
	struct node *next;
}node;
node *getnode() {//노드초기화
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = NULL;
	newnode->next = NULL;
	return newnode;
}
node *addLast(int data) {//노드추가
	node *newnode = getnode();
	newnode->data = data;
	return newnode;
}
node *removeFirst(node *p) {//제거
	node *tmp;
	tmp = p;
	p = p->next;
	free(tmp);//반환해주고
	return p;//새로운 p노드 리턴
}
void partition(node *H, node *HL1, node *HL2, int size) {
	int data;
	node *p = H;
	node *l1 = HL1, *l2 = HL2;//두개의 리스트 헤더와 놔눌 리스트 p헤더를 둔다,
	for (int i = 0; i < size / 2; i++) {//p리스트의 앞부분 절반을 리스트 1에 저장해준다.
		data = p->next->data;
		p->next = removeFirst(p->next);
		l1->next = addLast(data);
		l1 = l1->next;
	}
	for (int i = 0; i < size - (size / 2); i++) {
		data = p->next->data;
		p->next = removeFirst(p->next);
		l2->next = addLast(data);
		l2 = l2->next;
	}//p리스트의 앞부분 절반을 리스트 2에 저장해준다.
}
void merge(node *H, node *HL1, node *HL2) {
	int data;
	node *p = H;
	node *L1 = HL1->next;
	node *L2 = HL2->next;
	//partition에서 나눠준 두 리스트를 합쳐준다.
	while (L1 != NULL && L2 != NULL) {
		if (L1->data < L2->data) {//두리스트가 비어있지않을때 리스트1과 리스트2의 크기를 비교하여 저장해준다.
			data = L1->data;
			p->next = addLast(data);
			L1 = removeFirst(L1);
			p = p->next;
		}
		else {
			data = L2->data;
			p->next = addLast(data);
			L2 = removeFirst(L2);
			p = p->next;
		}
	}
	while (L1 != NULL) {//남은 리스트들을 저장해준다.
		data = L1->data;
		p->next = addLast(data);
		L1 = removeFirst(L1);
		p = p->next;
	}
	while (L2 != NULL) {//남은 리스트들을 저장해준다.
		data = L2->data;
		p->next = addLast(data);
		L2 = removeFirst(L2);
		p = p->next;
	}
}
void mergeSort(node *H, int size) {
	if (size > 1) {
		node *L1 = getnode(), *L2 = getnode();
		partition(H, L1, L2, size);//리스트두개로 나둔다.
		mergeSort(L1, size / 2);//나눠진 리스트를 기준으로도 재귀를 통하여 최대까지 쪼개준다.
		mergeSort(L2, size - size / 2);
		merge(H, L1, L2);//나눠진 리스트를 비교하여 합친다.
	}
}
void main()
{
	int n;
	int data;
	node *H = getnode();
	node *L = H;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		L->next = addLast(data);
		L = L->next;
	}
	mergeSort(H, n);
	node *p = H->next;
	while (p != NULL) {
		printf(" %d", p->data);
		p = p->next;
	}
}
