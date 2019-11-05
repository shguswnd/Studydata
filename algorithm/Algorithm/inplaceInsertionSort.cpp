#include<stdio.h>
#include<stdlib.h>
void inplaceInsertionSort(int *p, int n) {
	int save;
	int i, j;
	for (i = 1; i < n; i++)
	{
		save = p[i]; //현 자리값을 저장해준다.
		j = i - 1;
		while (j >= 0 && p[j] > save) {//j가 0보다 크며 세이브값보다도 크면 반복한다.
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = save;//반복이 끝난후 저장된 값을 바꿔준다.
	}
}
int main() {
	int n;
	int *p = NULL;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int));//배열생성.

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	inplaceInsertionSort(p, n);//삽입정렬
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);
}