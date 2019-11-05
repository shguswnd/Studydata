#include<stdio.h>
#include<stdlib.h>
void inplaceSelectionSort(int *p, int n) {
	int max;
	int pass;
	int tmp;
	for (int i = n - 1; i >= 1; i--) {//�ڿ��� ���� �񱳸� ���ش�
		pass = i - 1; //���غ��� �տ����� ���ĳ���.
		max = i;//�ִ밪
		for (int j = pass; j >= 0; j--) {
			if (p[max] < p[j]) //�ִ뺸�� ũ�� j���� �ٲ��ش�.
				max = j;
		}
		tmp = p[i];
		p[i] = p[max];
		p[max] = tmp;
	}
}
int main() {
	int n;
	int *p = NULL;

	scanf("%d", &n);//n���� �迭����.

	p = (int*)malloc(sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	inplaceSelectionSort(p, n);//���������Լ�
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);//���
}