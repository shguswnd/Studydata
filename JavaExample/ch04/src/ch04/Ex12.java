import java.util.Scanner;



class reservation{
	
	String [][] position = new String[3][10];
	String name;//�̸�
	int num;//�ڸ� ��ġ.
	int pos;//����ġ.
	public reservation()
	{
		for(int i=0;i<position.length;i++)//�¼��迭 �ʱ�ȭ
		{
			for(int j=0;j<position[i].length;j++)
			{
				position[i][j] = "---";
			}
		}
	}
	
	public void Print(int pos)
	{
		this.pos = pos-1;//���ǰ��� -1�Ͽ� �迭��ġ�� ������.
		if(pos == 1)//������ġ�� �Է¹޾� �ش��� �̸����
			System.out.print("S>>");
		else if(pos == 2)
			System.out.print("A>>");
		else if(pos == 3)
			System.out.print("B>>");
		
		for(int i=0;i<position[this.pos].length;i++)//�Է¹��� ���� ���� ���.
		{
			System.out.print(position[this.pos][i]+" ");
		}
		System.out.println();
			
	}
	public void Cancel(String name,int pos)
	{
		this.name = name;
		this.pos = pos-1;//���ǰ��� -1�Ͽ� �迭��ġ�� ������.
		
		for(int i=0;i<position[this.pos].length;i++)
		{
			if(position[this.pos][i].equals(name))//�¼��� �̸��� ã����� ---�ʱ�ȭ ����.
				{
					position[this.pos][i] = "---";
				}
		}
		
	}
	public void Input(String name,int num)
	{
		this.name = name;
		this.num = num-1;
		if(position[this.pos][this.num]=="---")//���ڸ� �϶��� ��������.
			position[this.pos][this.num] = this.name;
		else
			System.out.println("�ڸ��� �����ϴ�.!!!");
	}
	public void AllPrint()
	{
		for(int i=1;i<4;i++)//Print �޼ҵ�ȣ���� �Ͽ� �¼����� ������� ���.
			Print(i);
		System.out.println("��ȸ�� �Ϸ��Ͽ����ϴ�.>>>");
	}

}


public class Ex12 {

	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int Oper;
		int reserOp;
		String name;
		int num;
		
		reservation Reser= new reservation();
		
		Scanner scan = new Scanner(System.in);
		System.out.println("��ǰ�ܼ�ƮȦ ���� �ý����Դϴ�.");
		while(true)
		{	
			System.out.print("����:1, ��ȸ:2, ���:3, ������:4>>");
			Oper = scan.nextInt();
			
			switch(Oper)
			{
				case 1:
					System.out.print("�¼����� S(1), A(2), B(3)>>");
					reserOp = scan.nextInt();
					Reser.Print(reserOp);//���õ� �¼� ���.
					
					System.out.print("�̸�>>");
					name = scan.next();
					System.out.print("��ȣ>>");
					num = scan.nextInt();
					Reser.Input(name, num);//���� �޼ҵ�.
					break;
				case 2:
					Reser.AllPrint();//��ȸ�޼ҵ�.
					break;
				case 3:
					System.out.print("�¼����� S(1), A(2), B(3)>>");
					reserOp = scan.nextInt();
					Reser.Print(reserOp);
					System.out.print("�̸�>>");					
					name = scan.next();
					Reser.Cancel(name,reserOp);//��Ҹ޼ҵ�
					break;
				case 4://�ý��� ����
					scan.close();
					System.out.println("���α׷� ����");
					return;
				default:
					System.out.println("�߸� �Ǿ����� �ٽ� �Է� ���ּ���.");
			}
		}
	}

}
