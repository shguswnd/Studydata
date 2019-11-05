#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node *nextGroup, *nextElement;
	struct Node *preGroup, *preElement;
} Node;
//노드를 좌우상하 연결될수있게 만들었습니다
// 좌 preElement 우 nextElement 상preGroup 하nextGroup

typedef struct List {
	Node *H;
	Node *T;
	int Ele;
	char Gro;
}List;
//헤어와 테일러 그리고 각 리스트에 그룹와 엘리먼트 값들을  저장해주는 변수를 만들었습니다. Ele{1,2,3,4} , Gro {A,B,C,D,E}를 저장할 변수입니다.

void Init(List **NG, List **NE) {
	int El = 1;
	char Gr = 'A';
	List *list = (List*)malloc(sizeof(List));


	for (int i = 0; i < 5; i++)
	{
		list->H = (Node*)malloc(sizeof(Node));
		list->T = (Node*)malloc(sizeof(Node));
		list->H->preElement = NULL;
		list->H->preGroup = NULL;
		list->H->nextGroup = NULL;
		list->H->nextElement = NULL;
		list->T->preElement = NULL;
		list->T->preGroup = NULL;
		list->T->nextElement = NULL;
		list->T->nextGroup = NULL;
		NG[i] = (List*)malloc(sizeof(List));
		NG[i]->H = list->H;
		NG[i]->T = list->T;
		NG[i]->H->nextGroup = NG[i]->T;
		NG[i]->T->preGroup = NG[i]->H;
		NG[i]->Gro = Gr;
		Gr++;
	}

	for (int i = 0; i < 4; i++)
	{
		list->H = (Node*)malloc(sizeof(Node));
		list->T = (Node*)malloc(sizeof(Node));
		list->H->preElement = NULL;
		list->H->preGroup = NULL;
		list->H->nextGroup = NULL;
		list->H->nextElement = NULL;
		list->T->preElement = NULL;
		list->T->preGroup = NULL;
		list->T->nextElement = NULL;
		list->T->nextGroup = NULL;
		NE[i] = (List*)malloc(sizeof(List));
		NE[i]->H = list->H;
		NE[i]->T = list->T;
		NE[i]->H->nextElement = NE[i]->T;
		NE[i]->T->preElement = NE[i]->H;
		NE[i]->Ele = El;
		El++;
	}
}


/*
 리스트를 두개를 받아 하나는 그룹 하나는 엘리먼트 리스트를 만들어주었고
 다중연결리스트를 사용하기위해 이중포인터 리스트를 받게하였습니다.
노드가 상하좌우 가있듯. 헤트 테일러 각각도 상하좌우로 NULL을주었고  각각의 그룹,엘리먼트 리스트에 5개의헤더 5개의 테일,4개의 헤더 4개의 테일을
연결지어 주었습니다 .  i 순서에 맞게 Ele,Gro 값들을 저장해주었습니다.

*/
void addShare(List **NG, List **NE, int element, char group)
{
	int i = 0;
	int Gtrue = 0;
	int Etrue = 0;
	Node *newnode = (Node*)malloc(sizeof(Node));

	Node *HG = (Node*)malloc(sizeof(Node));    //그룹헤더저장변수
	Node *TG = (Node*)malloc(sizeof(Node));    //그룹트레일저장변수
	Node *HE = (Node*)malloc(sizeof(Node));   //엘리먼트헤더저장변수
	Node *TE = (Node*)malloc(sizeof(Node));   //엘리먼트트레일러저장변수

	newnode->nextGroup = NULL;
	newnode->nextElement = NULL;
	newnode->preGroup = NULL;
	newnode->preElement = NULL;

	for (int i = 0; i < 5; i++)
	{
		if (NG[i]->Gro == group)
		{
			HG = NG[i]->H;
			TG = NG[i]->T;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (NE[i]->Ele == element)
		{
			HE = NE[i]->H;
			TE = NE[i]->T;
			break;
		}
	}

	//반복문을 통하여 해당 그룹에 헤더와 트레일러  엘리멘트의 헤더와 트레일러 를 변수에 저장했습니다
	if (HG->nextGroup == TG && HE->nextElement == TE)
	{
		HE->nextElement = newnode;
		newnode->preElement = HE;
		newnode->nextElement = TE;
		TE->preElement = newnode;


		HG->nextGroup = newnode;
		newnode->preGroup = HG;
		newnode->nextGroup = TG;
		TG->preGroup = newnode;
	}
	else if (HG->nextGroup == TG && HE->nextElement != TE)
	{
		HG->nextGroup = newnode;
		newnode->preGroup = HG;
		newnode->nextGroup = TG;
		TG->preGroup = newnode;

		HE->nextElement->preElement = newnode;
		newnode->nextElement = HE->nextElement;
		newnode->preElement = HE;
		HE->nextElement = newnode;
	}
	else if (HG->nextGroup != TG && HE->nextElement == TE)
	{
		HE->nextElement = newnode;
		newnode->preElement = HE;
		newnode->nextElement = TE;
		TE->preElement = newnode;

		HG->nextGroup->preGroup = newnode;
		newnode->nextGroup = HG->nextGroup;
		newnode->preGroup = HG;
		HG->nextGroup = newnode;
	}
	else if (HG->nextGroup != TG && HE->nextElement != TE)
	{
		HE->nextElement->preElement = newnode;
		newnode->nextElement = HE->nextElement;
		newnode->preElement = HE;
		HE->nextElement = newnode;

		HG->nextGroup->preGroup = newnode;
		newnode->nextGroup = HG->nextGroup;
		newnode->preGroup = HG;
		HG->nextGroup = newnode;

	}

	//이중연결리스트로 조건에 따른 연결을 해주었습니다. 리스트에 헤더와 트레일만있을경우 , 헤더 노드 트레일 있는경우를 생각하여 놔누어주었습니다.
}
void traverseshareElements(List **NG, List **NE, char group) {
	int Etrue = 0;
	Node *HG = (Node*)malloc(sizeof(Node));
	Node *HE = (Node*)malloc(sizeof(Node));
	Node *TG = (Node*)malloc(sizeof(Node));
	Node *TE = (Node*)malloc(sizeof(Node));

	Node *T = (Node*)malloc(sizeof(Node));    // 반복하기 위해 저장시키는 임시변수.

	for (int i = 0; i < 5; i++)
	{
		if (group == NG[i]->Gro)
		{
			HG = NG[i]->H->nextGroup;
			TG = NG[i]->T;
			break;
		}
	}

	if (HG == TG)
	{
		printf("0");
		return;
	}
	else {
		while (1)
		{
			if (HG != TG)
			{
				for (int i = 0; i < 4; i++)
				{
					HE = NE[i]->H;
					T = HG;
					while (1)
					{
						T = T->preElement;
						if (T->preElement == NULL)
							break;
					}
					if (T == HE)
					{
						printf("%d ", NE[i]->Ele);
						Etrue++;
						break;
					}
					else
						continue;
				}
			}

			else if (HG == TG)
				break;
			HG = HG->nextGroup;
		}
	}

	if (Etrue == 0)
		printf("0");

}
/*
   각 그룹의 해당되는 엘리먼트값을 찾기위하여 주소값을 비교하게 만들었는데 만약 B그룹의 엘리먼트을 찾으려면 해당그룹의 저장되어있는
   노드들을 그룹의 테일러 만날때까지 밑으로 내려주면서 동시에 엘리멘트를 찾기위하여 노드를 >preElement 좌로 움직이고
   좌로 움직였을때 엘리멘트 헤더 주소가 되어지면 헤더에 저장되어있는  엘리멘트값을 저장한변수 Ele를 출력하게 해주었습니다.

*/
void traverseShareGroups(List **NG, List **NE, int element)
{
	int Gtrue = 0;
	Node *HG = (Node*)malloc(sizeof(Node));
	Node *TG = (Node*)malloc(sizeof(Node));
	Node *HE = (Node*)malloc(sizeof(Node));
	Node *TE = (Node*)malloc(sizeof(Node));
	Node *T = (Node*)malloc(sizeof(Node));
	HE = NE[element - 1]->H->nextElement;
	T = NE[element - 1]->H->nextElement;
	TE = NE[element - 1]->T;
	if (HE == TE)
	{
		printf("0");
		return;
	}
	else {
		while (1)
		{
			if (HE != TE)
			{
				for (int i = 0; i < 5; i++)
				{
					HG = NG[i]->H;
					T = HE;
					while (1)
					{
						T = T->preGroup;
						if (T->preGroup == NULL)
							break;
					}
					if (T == HG)
					{
						printf("%c ", NG[i]->Gro);
						Gtrue++;
						break;
					}
					else
						continue;
				}
			}

			else if (HE == TE)
				break;
			HE = HE->nextElement;
		}
	}

	if (Gtrue == 0)
		printf("0");


}
/*
  위 엘리멘트와 마찬가지로
  그룹을 알고싶을때 저장되어있는 엘리먼트의 노드를 엘리멘트 테일러만날때까지 돌리면서 각 노드의 그룹헤트를 만나서 그룹을 출력하기위해
  ->preGroup 하여 헤더주소까지 찾아갑니다. 그후 헤더에 저장되어있는 그룹을 출력.

*/

Node * removeShare(List **NG, List **NE, int element, char group)
{
	int Rtrue = 0;
	Node *Dummy = (Node*)malloc(sizeof(Node));
	Node *HG = (Node*)malloc(sizeof(Node));
	Node *HE = (Node*)malloc(sizeof(Node));
	Node *TG = (Node*)malloc(sizeof(Node));
	Node *TE = (Node*)malloc(sizeof(Node));
	Node *T = (Node*)malloc(sizeof(Node));

	HE = NE[element - 1]->H->nextElement;
	TE = NE[element - 1]->T;
	T = NE[element - 1]->H->nextElement;
	for (int i = 0; i < 5; i++)
	{
		if (group == NG[i]->Gro)
		{
			HG = NG[i]->H->nextGroup;
			TG = NG[i]->T;
			break;
		}
	}
	while (1)
	{
		HE = T;
		while (1)
		{
			if (HE == HG)
			{

				Dummy = HE;

				HE->preElement->nextElement = HE->nextElement;
				HE->nextElement->preElement = HE->preElement;
				HG->preGroup->nextGroup = HG->nextGroup;
				HG->nextGroup->preGroup = HG->preGroup;

				Rtrue = 1;
				if (Rtrue == 1)
					printf("OK\n");
				return Dummy;
			}
			HE = HE->nextElement;

			if (HE == TE)
				break;
		}
		HG = HG->nextGroup;
		if (HG == TG)
			break;
	}
	if (Rtrue == 0)
		printf("삭제 할께 없습니다\n");

}
/*
	노드 삭제시 쓰레기가되는 노드를 더미 Dummy 변수에 저장후 리턴값을 보내준후 main에서 free해주었습니다.
*/

int main()
{
	char sw;
	char get;
	char a;
	int element;
	char group;
	List **NG = (List**)malloc(5 * sizeof(List*));
	List **NE = (List**)malloc(4 * sizeof(List*));
	Node *Dummy = (Node*)malloc(sizeof(Node));
	Init(NG, NE);


	while (1)
	{

		scanf("%c", &sw);
		switch (sw)
		{
		case 'a':
		{
			scanf("%d %c", &element, &group);
			getchar();
			addShare(NG, NE, element, group);
			printf("OK\n");
			break;
		}
		case 'g':
		{
			scanf("%d", &element);
			getchar();
			traverseShareGroups(NG, NE, element);
			printf("\n");
			break;
		}
		case 'e':
		{
			getchar();
			scanf("%c", &group);
			getchar();
			traverseshareElements(NG, NE, group);
			printf("\n");
			break;
		}
		case 'r':
		{
			scanf("%d %c", &element, &group);
			getchar();
			Dummy = removeShare(NG, NE, element, group);
			free(Dummy);
			break;
		}
		case 'q':
		{
			return 0;
		}
	}
	}
}
