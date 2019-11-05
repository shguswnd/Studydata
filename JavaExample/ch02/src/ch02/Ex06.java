package ch02;

import java.util.Scanner;

public class Ex06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int ele;
		int cnt=0;
		int no;
		Scanner scan = new Scanner(System.in);
		
		System.out.println("1~99 사이의 정수를 입력하시오>>");
		ele = scan.nextInt();
		
		while(true)
		{
			if(((ele%10)%3)==0)
				cnt++;
			if((ele/10)==0)
				break;
			ele = ele/10;
			
		}
		if(cnt==1)
			System.out.println("박수짝");
		else if(cnt==2)
			System.out.println("박수짝짝");
	}

}
