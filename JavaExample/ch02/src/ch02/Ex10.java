package ch02;

import java.util.Scanner;

public class Ex10 {
	public static boolean rect(int x1,int y1 , int r1,int x2,int y2,int r2)
	{
		double disten;
		disten = Math.sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
		if(disten <= r1+r2)
			return true;
		else
			return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int x1,y1,r1,x2,y2,r2;
	
		Scanner scan = new Scanner(System.in);
		
		System.out.println("ù��° ���� �߽ɰ� ������ �Է�>>>");
		x1 = scan.nextInt();
		y1 = scan.nextInt();
		r1 = scan.nextInt();
		
		System.out.println("�ι�° ���� �߽ɰ� ������ �Է�>>>");
		x2 = scan.nextInt();
		y2 = scan.nextInt();
		r2 = scan.nextInt();
		
		if(rect(x1,y1,r1,x2,y2,r2))
			System.out.println("�ο��� ���� ��ģ��");
		else
			System.out.println("�ο��� �Ȱ�ģ��");
		
	}

}
