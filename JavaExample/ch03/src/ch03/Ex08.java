package ch03;

import java.util.Scanner;

public class Ex08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N;
		int[] arr ;
		Scanner scan =new Scanner(System.in);
		
		System.out.println("정수 몇개?");
		N = scan.nextInt();
		
		arr = new int[N];//정수를 입력하여 정수만큼의 배열을 new생성해줌.
		
		for(int i=0;i<arr.length;i++)//생성된 배열크기만큼 반복문.
		{
			arr[i] = (int)(Math.random()*100+1);//1~100까지의 랜덤숫자를 저장해줌.
		}
		
		for(int i=1;i<arr.length;i++)//출력.
		{
			if(i%10==0)System.out.println();
			System.out.print(arr[i]+" ");
		}
	}

}
