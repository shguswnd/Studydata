package ch04;

import java.util.Scanner;

class Phone{
	String name;
	int tel;
	
	public Phone(String name, int tel)
	{
		this.name  = name;
		this.tel = tel;
	}
	
}
public class Ex08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
				
		System.out.print("�ο��� >>");
		int N = scan.nextInt();
		
		Phone p[] = new Phone[N];
		for(int i=0;i<p.length;i++)
		{
			System.out.print("�̸��� ��ȭ��ȣ(�̸��� ��ȣ�� �� ĭ���� �Է�)>>");
			String name = scan.next();
			int tel = scan.nextInt();
			
			p[i] = new Phone(name,tel);
		}
		System.out.println("����Ǿ����ϴ�...");
		while(true)
		{
			int cnt =0;
			System.out.print("�˻��� �̸�>>>");
			String name = scan.next();
		
			if(name.equals("�׸�"))
				return;
			for(int i=0;i<p.length;i++)
			{
				
				if(name.equals(p[i].name))
				{
						System.out.println(p[i].name + "��ȣ�� "+p[i].tel +" �Դϴ�.");
						cnt--;
						break;
				}
				cnt++;
			}
			if(cnt==p.length)
				System.out.println("�˻��� �̸��� ����.");
		
				
		}
		
		
	}

}
