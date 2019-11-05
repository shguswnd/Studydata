package ch02;

import java.util.Scanner;

public class Ex02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int ele;
		Scanner scan = new Scanner(System.in);
		System.out.println("2자리 정수 입력(10~99)>>>");
		ele = scan.nextInt();
		if((ele/10)==(ele%10))
			System.out.println("Yes! 10의 자리와 1의 자리가 같습니다.");
		else
			System.out.println("No! 10의 자리와 1의 자리가 다릅니다.");
			
	}

}
