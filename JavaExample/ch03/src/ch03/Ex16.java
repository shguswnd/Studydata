package ch03;

import java.util.Scanner;

public class Ex16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str[] = {"����","����","��"};
		String no;
		Scanner scan = new Scanner(System.in);
		System.out.println("��ǻ�Ϳ� ���� ���� �� ������ �մϴ�.");
		
		while(true)
		{
			int n = (int)(Math.random()*3);
			
			System.out.print("���� ���� ��!!>>");
			no  = scan.next();
			if(no.equals("�׸�"))
				return;
			System.out.print("����� = " + no + " , ��ǻ�� = "+str[n]+", ");
			
			if(str[n].equals(no))
				System.out.println("�����ϴ�.");
			else if(str[n].equals("����"))
			{
				if(no.equals("����"))
					System.out.println("�̰���ϴ�.");
				else if(no.equals("��"))
					System.out.println("�����ϴ�.");
			}
			else if(str[n].equals("����"))
			{
				if(no.equals("��"))
					System.out.println("�̰���ϴ�.");
				else if(no.equals("����"))
					System.out.println("�����ϴ�.");
			}
			else if(str[n].equals("��"))
			{
				if(no.equals("����"))
					System.out.println("�̰���ϴ�.");
				else if(no.equals("����"))
					System.out.println("�����ϴ�.");
			}
		}
	}

}
