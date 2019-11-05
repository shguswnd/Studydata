#include<stdio.h>
#include<stdlib.h>
void inplaceSelectionSort(int *p, int n) {
	int max;
	int pass;
	int tmp;
	for (int i = n - 1; i >= 1; i--) {//뒤에서 부터 비교를 해준다
		pass = i - 1; //기준보다 앞에꺼를 나파내줌.
		max = i;//최대값
		for (int j = pass; j >= 0; j--) {
			if (p[max] < p[j]) //최대보다 크면 j값을 바꿔준다.
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

	scanf("%d", &n);//n개의 배열생성.

	p = (int*)malloc(sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	inplaceSelectionSort(p, n);//선택정렬함수
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);//출력
}