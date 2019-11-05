#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int find_pivot_index(int l, int r) {//�Ǻ����� ������ݴϴ�.
	int a, b, c;
	srand((int)time(NULL));

	a = rand() % (r - l + 1) + l;
	b = rand() % (r - l + 1) + l;
	c = rand() % (r - l + 1) + l;
	//3���� �������� ������ ���� �߰����� ����մϴ�.
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
	int i = l, j = r - 1;//i�� �ǿ��� j�� �ǿ����ʿ��� ��ĭ���� �׸��� �Ǻ� ������ �� ���������� �Ѵ�.
	swap(&A[r], &A[k]);
	while (i <= j) {
		while (i <= j && A[i] <= pivot) {//�Ǻ��������� ũ�Ⱑ ������ ����i�� �����ɱ뿴�� j���� ������ i�� ��� �̵��Ѵ�. 
			i = i + 1;
		}
		while (j >= i && A[j] >= pivot)//j�� i���� �׸� ���� �Ǻ����� ũ�� ��� �̵��Ѵ�.
			j = j - 1;
		if (i < j)//�̵��� �������ش�.
			swap(&A[i], &A[j]);
	}
	*a = i;
	*b = i;
	swap(&A[i], &A[r]);//���� �Ǻ��� �ٲ۴�.
}
void inPlaceQuickSort(int *A, int l, int r) {
	int a = 0, b = 0;
	if (l >= r)
		return;
	int k = find_pivot_index(l, r);//�Ǻ� ���������Ͽ� ���ڸ� �����Ŀ� ���.
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
