package ch03;

import java.util.Scanner;

public class Ex04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		System.out.print("�ҹ��� ���ĺ� �ϳ��� �Է��Ͻÿ�>>");
		String s = scan.next();
		
		char c = s.charAt(0);
		char a='a';
		do
		{
			if(a==c)
			{
				System.out.print(a);
				c--;
				System.out.println();
				a = 'a';
			}			
			System.out.print(a);
			a++;
			
		}while(c!='a');
		
	}

}
