#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int find_pivot_index(int l, int r) {//피봇값을 만들어줍니다.
	int a, b, c;
	srand((int)time(NULL));

	a = rand() % (r - l + 1) + l;
	b = rand() % (r - l + 1) + l;
	c = rand() % (r - l + 1) + l;
	//3개의 랜덤값을 만든후 그중 중간값을 사용합니다.
	if (a >= b && a >= c)
	{
		if (b >= c)
			return b;
		else
			return c;
	}
	else if (b >= a && b >= c) {
		if (a >= c)
			return a;
		else
			return c;
	}
	else if (c >= a && c >= b) {
		if (c >= b)
			return a;
		else
			return b;
	}
}
void inPlacePartition(int *A, int l, int r, int k, int *a, int *b) {
	int pivot = A[k];
	int i = l, j = r - 1;//i를 맨왼쪽 j를 맨오른쪽에서 한칸왼쪽 그리고 피봇 기준을 맨 오른쪽으로 한다.
	swap(&A[r], &A[k]);
	while (i <= j) {
		while (i <= j && A[i] <= pivot) {//피봇기준으로 크기가 작으며 왼쪽i가 오른쪼깅였던 j보다 작으면 i을 계속 이동한다. 
			i = i + 1;
		}
		while (j >= i && A[j] >= pivot)//j도 i보다 그며 기준 피봇보다 크면 계속 이동한다.
			j = j - 1;
		if (i < j)//이동후 스왑해준다.
			swap(&A[i], &A[j]);
	}
	*a = i;
	*b = i;
	swap(&A[i], &A[r]);//기준 피봇을 바꾼다.
}
void inPlaceQuickSort(int *A, int l, int r) {
	int a = 0, b = 0;
	if (l >= r)
		return;
	int k = find_pivot_index(l, r);//피봇 기준으로하여 제자리 퀵정렬에 사용.
	inPlacePartition(A, l, r, k, &a, &b);
	inPlaceQuickSort(A, l, a - 1);
	inPlaceQuickSort(A, b + 1, r);
}
void main()
{
	int N;
	int *A;
	scanf("%d", &N);
	A = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	inPlaceQuickSort(A, 0, N - 1);
	for (int i = 0; i < N; i++)
		printf(" %d", A[i]);
}
