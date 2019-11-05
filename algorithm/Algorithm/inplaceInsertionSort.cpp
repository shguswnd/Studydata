#include<stdio.h>
#include<stdlib.h>
void inplaceInsertionSort(int *p, int n) {
	int save;
	int i, j;
	for (i = 1; i < n; i++)
	{
		save = p[i]; //�� �ڸ����� �������ش�.
		j = i - 1;
		while (j >= 0 && p[j] > save) {//j�� 0���� ũ�� ���̺갪���ٵ� ũ�� �ݺ��Ѵ�.
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = save;//�ݺ��� ������ ����� ���� �ٲ��ش�.
	}
}
int main() {
	int n;
	int *p = NULL;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int));//�迭����.

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	inplaceInsertionSort(p, n);//��������
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);
}