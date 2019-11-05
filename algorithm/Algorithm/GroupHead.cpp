#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node *nextGroup, *nextElement;
	struct Node *preGroup, *preElement;
} Node;
//��带 �¿���� ����ɼ��ְ� ��������ϴ�
// �� preElement �� nextElement ��preGroup ��nextGroup

typedef struct List {
	Node *H;
	Node *T;
	int Ele;
	char Gro;
}List;
//���� ���Ϸ� �׸��� �� ����Ʈ�� �׷�� ������Ʈ ������  �������ִ� ������ ��������ϴ�. Ele{1,2,3,4} , Gro {A,B,C,D,E}�� ������ �����Դϴ�.

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
 ����Ʈ�� �ΰ��� �޾� �ϳ��� �׷� �ϳ��� ������Ʈ ����Ʈ�� ������־���
 ���߿��Ḯ��Ʈ�� ����ϱ����� ���������� ����Ʈ�� �ް��Ͽ����ϴ�.
��尡 �����¿� ���ֵ�. ��Ʈ ���Ϸ� ������ �����¿�� NULL���־���  ������ �׷�,������Ʈ ����Ʈ�� 5������� 5���� ����,4���� ��� 4���� ������
�������� �־����ϴ� .  i ������ �°� Ele,Gro ������ �������־����ϴ�.

*/
void addShare(List **NG, List **NE, int element, char group)
{
	int i = 0;
	int Gtrue = 0;
	int Etrue = 0;
	Node *newnode = (Node*)malloc(sizeof(Node));

	Node *HG = (Node*)malloc(sizeof(Node));    //�׷�������庯��
	Node *TG = (Node*)malloc(sizeof(Node));    //�׷�Ʈ�������庯��
	Node *HE = (Node*)malloc(sizeof(Node));   //������Ʈ������庯��
	Node *TE = (Node*)malloc(sizeof(Node));   //������ƮƮ���Ϸ����庯��

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

	//�ݺ����� ���Ͽ� �ش� �׷쿡 ����� Ʈ���Ϸ�  ������Ʈ�� ����� Ʈ���Ϸ� �� ������ �����߽��ϴ�
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

	//���߿��Ḯ��Ʈ�� ���ǿ� ���� ������ ���־����ϴ�. ����Ʈ�� ����� Ʈ���ϸ�������� , ��� ��� Ʈ���� �ִ°�츦 �����Ͽ� �������־����ϴ�.
}
void traverseshareElements(List **NG, List **NE, char group) {
	int Etrue = 0;
	Node *HG = (Node*)malloc(sizeof(Node));
	Node *HE = (Node*)malloc(sizeof(Node));
	Node *TG = (Node*)malloc(sizeof(Node));
	Node *TE = (Node*)malloc(sizeof(Node));

	Node *T = (Node*)malloc(sizeof(Node));    // �ݺ��ϱ� ���� �����Ű�� �ӽú���.

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
   �� �׷��� �ش�Ǵ� ������Ʈ���� ã�����Ͽ� �ּҰ��� ���ϰ� ������µ� ���� B�׷��� ������Ʈ�� ã������ �ش�׷��� ����Ǿ��ִ�
   ������ �׷��� ���Ϸ� ���������� ������ �����ָ鼭 ���ÿ� ������Ʈ�� ã�����Ͽ� ��带 >preElement �·� �����̰�
   �·� ���������� ������Ʈ ��� �ּҰ� �Ǿ����� ����� ����Ǿ��ִ�  ������Ʈ���� �����Ѻ��� Ele�� ����ϰ� ���־����ϴ�.

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
  �� ������Ʈ�� ����������
  �׷��� �˰������ ����Ǿ��ִ� ������Ʈ�� ��带 ������Ʈ ���Ϸ����������� �����鼭 �� ����� �׷���Ʈ�� ������ �׷��� ����ϱ�����
  ->preGroup �Ͽ� ����ּұ��� ã�ư��ϴ�. ���� ����� ����Ǿ��ִ� �׷��� ���.

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
		printf("���� �Ҳ� �����ϴ�\n");

}
/*
	��� ������ �����Ⱑ�Ǵ� ��带 ���� Dummy ������ ������ ���ϰ��� �������� main���� free���־����ϴ�.
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
