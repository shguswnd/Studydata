package ch03;

import java.util.Scanner;

public class Ex08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N;
		int[] arr ;
		Scanner scan =new Scanner(System.in);
		
		System.out.println("���� �?");
		N = scan.nextInt();
		
		arr = new int[N];//������ �Է��Ͽ� ������ŭ�� �迭�� new��������.
		
		for(int i=0;i<arr.length;i++)//������ �迭ũ�⸸ŭ �ݺ���.
		{
			arr[i] = (int)(Math.random()*100+1);//1~100������ �������ڸ� ��������.
		}
		
		for(int i=1;i<arr.length;i++)//���.
		{
			if(i%10==0)System.out.println();
			System.out.print(arr[i]+" ");
		}
	}

}
