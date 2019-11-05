#include<stdio.h>
#include<stdlib.h>
typedef struct node {//���
	int data;
	struct node *next;
}node;
node *getnode() {//����ʱ�ȭ
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = NULL;
	newnode->next = NULL;
	return newnode;
}
node *addLast(int data) {//����߰�
	node *newnode = getnode();
	newnode->data = data;
	return newnode;
}
node *removeFirst(node *p) {//����
	node *tmp;
	tmp = p;
	p = p->next;
	free(tmp);//��ȯ���ְ�
	return p;//���ο� p��� ����
}
void partition(node *H, node *HL1, node *HL2, int size) {
	int data;
	node *p = H;
	node *l1 = HL1, *l2 = HL2;//�ΰ��� ����Ʈ ����� ���� ����Ʈ p����� �д�,
	for (int i = 0; i < size / 2; i++) {//p����Ʈ�� �պκ� ������ ����Ʈ 1�� �������ش�.
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
	}//p����Ʈ�� �պκ� ������ ����Ʈ 2�� �������ش�.
}
void merge(node *H, node *HL1, node *HL2) {
	int data;
	node *p = H;
	node *L1 = HL1->next;
	node *L2 = HL2->next;
	//partition���� ������ �� ����Ʈ�� �����ش�.
	while (L1 != NULL && L2 != NULL) {
		if (L1->data < L2->data) {//�θ���Ʈ�� ������������� ����Ʈ1�� ����Ʈ2�� ũ�⸦ ���Ͽ� �������ش�.
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
	while (L1 != NULL) {//���� ����Ʈ���� �������ش�.
		data = L1->data;
		p->next = addLast(data);
		L1 = removeFirst(L1);
		p = p->next;
	}
	while (L2 != NULL) {//���� ����Ʈ���� �������ش�.
		data = L2->data;
		p->next = addLast(data);
		L2 = removeFirst(L2);
		p = p->next;
	}
}
void mergeSort(node *H, int size) {
	if (size > 1) {
		node *L1 = getnode(), *L2 = getnode();
		partition(H, L1, L2, size);//����Ʈ�ΰ��� ���д�.
		mergeSort(L1, size / 2);//������ ����Ʈ�� �������ε� ��͸� ���Ͽ� �ִ���� �ɰ��ش�.
		mergeSort(L2, size - size / 2);
		merge(H, L1, L2);//������ ����Ʈ�� ���Ͽ� ��ģ��.
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
