package ch02;

import java.util.Scanner;

public class Ex02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int ele;
		Scanner scan = new Scanner(System.in);
		System.out.println("2�ڸ� ���� �Է�(10~99)>>>");
		ele = scan.nextInt();
		if((ele/10)==(ele%10))
			System.out.println("Yes! 10�� �ڸ��� 1�� �ڸ��� �����ϴ�.");
		else
			System.out.println("No! 10�� �ڸ��� 1�� �ڸ��� �ٸ��ϴ�.");
			
	}

}
