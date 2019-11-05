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
		printf("<< 자료구조 예상학점은?>> \n");
		runDecisionTree(root);
		printf("\n");
		printf("\n");

	}
}




/*
tree "매일 공부를 하였습니까?" F1 "평균 10시간이상 공부를 했나요?" F2 "주3일 이상은 공부 하셨나요?"
F3 "공부의 내용을 다 이해하시나요?"F4 "평균 7시간 이상 공부를 했나요?" F5 "평균 2시간 이상은 공부를 했나요?"
F6 "주 하루는 공부를 하시나요?" F7 "예습복습을 하셨나요?" F8 "하루평균 4시간은 공부를 하시나요?"
F9 "수업은 잘 들으시나요?" F10 "시험 기간때는 공부를 하시나요?"
exter1 당신은 A+맞기에 적합하군요 축하해요~" exter2 "운이 좋다면 A+도 가능해요" exter3 "A입니다 예습복습을 하시면 A+도 가능해요."
exter4 "A입니다 공부시간을 늘려봐요~" exter5 "이정도 시간 투자로 B+도 과분합니다." exter6 "B가 나온다면 당신은 행운아입니다."
exter7 "C+입니다. 공부 시간과 일수를 늘려봐요." exter8 "C+입니다. 당신은 노력을 안합니다." exter9 "C입니다 재수강 가즈아~"
exter10 "D+입니다 재수강떄는 열심히 해봐요" exter11 "D입니다 재수강해도 성적은 안오를것입니다."
exter12 "당신은 가능성이없습니다 자퇴를 추천드려요"

**트리 구조는
											  tree


								F1										F2

					F3			  F4					    F5					F6


			exter1    F7	exter4       F8			 exter7 exter8	     	exter9	F9

				exter2 exter3      exter5 exter6						 	exter10      F10

																					exter11 exter12
 이렇게 구성되어있습니다.
 */