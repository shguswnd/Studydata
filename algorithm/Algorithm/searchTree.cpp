#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
	int key;
	struct treenode *parent;
	struct treenode *rlink;
	struct treenode *llink;
}tree;
tree *root = NULL;

tree *getNode() {
	tree *newnode = (tree*)malloc(sizeof(tree));
	newnode->parent = newnode->llink = newnode->rlink = NULL;
	return newnode;
}

int isExternal(tree *w) {
	if (w->llink == NULL && w->rlink == NULL)
		return 1;
	else
		return 0;
}

tree *treeSearch(tree *v, int k) {
	if (isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->llink, k);
	else
		return treeSearch(v->rlink, k);
}

void findElement(int k) {
	tree *w = treeSearch(root, k);
	if (isExternal(w))
		printf("X\n");
	else
		printf("%d\n", w->key);
}
void expandExternal(tree *w) {
	w->llink = getNode();
	w->rlink = getNode();
	w->llink->parent = w->rlink->parent = w;
}
void insertItem(int k) {
	tree *w = treeSearch(root, k);

	if (!isExternal(w))
		return;
	else {
		w->key = k;
		expandExternal(w);
	}
}
tree *inOrderSucc(tree *w) {
	w = w->rlink;
	while (!isExternal(w))
		w = w->llink;
	return w->parent;
}
tree *sibling(tree *z) {
	tree *w = z->parent;
	if (w->llink == z)
		return w->rlink;
	else
		return w->llink;
}
void reduceExternal(tree *z) {
	tree *w = z->parent, *zs, *g;
	zs = sibling(z);
	if (w == root) {
		root = zs;
		zs->parent = NULL;
	}
	else {
		g = w->parent;
		zs->parent = g;
		if (w == g->llink)
			g->llink = zs;
		else
			g->rlink = zs;
	}
	free(z);
	free(w);
}
void removeElement(int k) {
	tree *w, *z, *y;
	w = treeSearch(root, k);
	if (isExternal(w)) {
		printf("X\n");
		return;
	}
	printf("%d\n", w->key);
	z = w->llink;
	if (!isExternal(z))
		z = w->rlink;
	if (isExternal(z))
		reduceExternal(z);
	else {
		y = inOrderSucc(w);
		z = y->llink;
		w->key = y->key;
		reduceExternal(z);
	}
}
void preorder(tree *r) {
	if (!isExternal(r)) {
		printf(" %d", r->key);
		preorder(r->llink);
		preorder(r->rlink);
	}
}void main() {
	char c;
	int k;
	root = getNode();

	while (1) {
		scanf("%c", &c);

		if (c == 'i') {
			scanf("%d", &k);
			getchar();
			insertItem(k);
		}
		else if (c == 'p') {
			getchar();
			if (isExternal(root))
				continue;
			preorder(root);
			printf("\n");
		}
		else if (c == 's') {
			scanf("%d", &k);
			getchar();
			findElement(k);
		}
		else if (c == 'd') {
			scanf("%d", &k);
			getchar();
			removeElement(k);
		}
		else
			return;
	}
}