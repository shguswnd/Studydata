package ch02;

import java.util.Scanner;

public class Ex12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String instruct;
		float a,b;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("���� >>");
		a = scan.nextFloat();
		instruct = scan.next();
		b = scan.nextFloat();
		if(instruct.equals("+"))
		{
			System.out.println(a+b);
		}
		else if(instruct.equals("-"))
		{
			System.out.println(a-b);
		}
		else if(instruct.equals("*"))
		{
			System.out.println(a*b);
		}
		else if(instruct.equals("/"))
		{
			if(b==0)
				System.out.println("0���� ������ ����.");
			else
				System.out.println(a/b);
		}
	}

}
