#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
	char *elem;
	struct Node* left;
	struct Node* right;

}Node;

Node *Init()
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	return newNode;
}
Node* makeExternalNode()
{
	Node *tree = Init();
	char str[50];
	char YesNo[4];
	int size = 0;
	printf("Enter decision:");
	gets(str);
	size = strlen(str) + 1;
	tree->elem = (char*)malloc(size * sizeof(char));
	strcpy(tree->elem, str);

	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
Node* makeInternalNode()
{
	Node *tree = Init();
	char str[50];
	int YesNo;
	int size = 0;
	printf("Enter question:");
	gets(str);
	size = strlen(str) + 1;
	tree->elem = (char*)malloc(size * sizeof(char));
	strcpy(tree->elem, str);
	printf("Question if yes to '%s'?", tree->elem);
	scanf("%d", &YesNo);
	getchar();
	if (YesNo == 1)
	{
		tree->left = makeInternalNode();
	}
	else if (YesNo == 2)
	{
		tree->left = makeExternalNode();
	}

	printf("Question if no to '%s'?", tree->elem);


	scanf("%d", &YesNo);
	getchar();
	if (YesNo == 1)
	{
		tree->right = makeInternalNode();
	}
	else if (YesNo == 2)
	{
		tree->right = makeExternalNode();
	}

	return tree;
}
Node * buildDecisionTree()
{
	return makeInternalNode();
}
void  runDecisionTree(Node* root)
{
	char YesNo[4];
	printf("%s: ", root->elem);
	if (root->left != NULL || root->right != NULL)
	{
		scanf("%s", YesNo);

		if (strcmp(YesNo, "yes") == 0)
			runDecisionTree(root->left);
		else if (strcmp(YesNo, "no") == 0)
		{
			runDecisionTree(root->right);
		}
	}



}

int main() {

	Node *root = Init();

	root = buildDecisionTree();
	for (int i = 0; i < 3; i++)
	{
		printf("<< �ڷᱸ�� ����������?>> \n");
		runDecisionTree(root);
		printf("\n");
		printf("\n");

	}
}




/*
tree "���� ���θ� �Ͽ����ϱ�?" F1 "��� 10�ð��̻� ���θ� �߳���?" F2 "��3�� �̻��� ���� �ϼ̳���?"
F3 "������ ������ �� �����Ͻó���?"F4 "��� 7�ð� �̻� ���θ� �߳���?" F5 "��� 2�ð� �̻��� ���θ� �߳���?"
F6 "�� �Ϸ�� ���θ� �Ͻó���?" F7 "���������� �ϼ̳���?" F8 "�Ϸ���� 4�ð��� ���θ� �Ͻó���?"
F9 "������ �� �����ó���?" F10 "���� �Ⱓ���� ���θ� �Ͻó���?"
exter1 ����� A+�±⿡ �����ϱ��� �����ؿ�~" exter2 "���� ���ٸ� A+�� �����ؿ�" exter3 "A�Դϴ� ���������� �Ͻø� A+�� �����ؿ�."
exter4 "A�Դϴ� ���νð��� �÷�����~" exter5 "������ �ð� ���ڷ� B+�� �����մϴ�." exter6 "B�� ���´ٸ� ����� �����Դϴ�."
exter7 "C+�Դϴ�. ���� �ð��� �ϼ��� �÷�����." exter8 "C+�Դϴ�. ����� ����� ���մϴ�." exter9 "C�Դϴ� ����� �����~"
exter10 "D+�Դϴ� ��������� ������ �غ���" exter11 "D�Դϴ� ������ص� ������ �ȿ������Դϴ�."
exter12 "����� ���ɼ��̾����ϴ� ���� ��õ�����"

**Ʈ�� ������
											  tree


								F1										F2

					F3			  F4					    F5					F6


			exter1    F7	exter4       F8			 exter7 exter8	     	exter9	F9

				exter2 exter3      exter5 exter6						 	exter10      F10

																					exter11 exter12
 �̷��� �����Ǿ��ֽ��ϴ�.
 */