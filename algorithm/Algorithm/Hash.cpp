#include<stdio.h>
#include<stdlib.h>

typedef struct hashnode {
	int element;
	struct hashnode *link;
}node;

typedef struct HashList {
	node *H;
}Hash;

void initBucketArray(Hash **hash, int M) {
	for (int i = 0; i < M; i++) {
		hash[i] = (Hash*)malloc(sizeof(Hash));
		hash[i]->H = (node*)malloc(sizeof(node));
		hash[i]->H->element = hash[i]->H->link = NULL;
	}
}
void findElement(Hash **hash, int key, int element) {
	node *pre = hash[key]->H->link;
	int cnt = 0;
	while (pre != NULL) {
		cnt++;
		if (pre->element == element) {
			printf("%d\n", cnt);
			return;
		}
		pre = pre->link;
	}
	printf("0\n");
}
void insertItem(Hash **hash, int key, int element) {

	node *newNode = (node*)malloc(sizeof(node));
	newNode->element = element;
	newNode->link = hash[key]->H->link;
	hash[key]->H->link = newNode;
}
void removeElement(Hash **hash, int key, int element) {
	node *pre = hash[key]->H->link;
	node *tmp = hash[key]->H;
	int cnt = 0;
	while (pre != NULL) {
		cnt++;
		if (pre->element == element) {
			printf("%d\n", cnt);
			tmp->link = pre->link;
			free(pre);
			return;
		}
		pre = pre->link;
		tmp = tmp->link;
	}
	printf("0\n");
}

void print(Hash **hash, int M) {
	node *pre;
	for (int i = 0; i < M; i++) {
		pre = hash[i]->H->link;
		while (pre != NULL) {
			printf(" %d", pre->element);
			pre = pre->link;
		}
	}
	printf("\n");
}
void freeHash(Hash** hash, int M) {
	for (int i = 0; i < M; i++) {
		node *pre = hash[i]->H;
		node *tmp;
		while (pre != NULL) {
			tmp = pre;
			pre = pre->link;
			free(tmp);
		}
	}
	free(hash);
}

int main() {
	Hash **hash;
	int M;
	int key;
	int element;
	char operation;
	scanf("%d", &M);
	hash = (Hash**)malloc(sizeof(Hash*)*M);
	initBucketArray(hash, M);

	while (1) {
		scanf("%c", &operation);
		switch (operation)
		{
		case 'i':
			scanf("%d", &element);
			key = element % M;
			insertItem(hash, key, element);
			break;
		case 's':
			scanf("%d", &element);
			key = element % M;
			findElement(hash, key, element);
			break;
		case 'd':
			scanf("%d", &element);
			key = element % M;
			removeElement(hash, key, element);
			break;
		case 'p':
			print(hash, M);
			break;
		case 'e':
			freeHash(hash, M);
			return;
			break;
		}
	}


}