package ch03;

import java.util.Scanner;

public class Ex06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] unit = {50000,10000,1000,500,100,50,10,1};
		int N;
		int i=0,cnt=0;
		Scanner scan = new Scanner(System.in);
		System.out.print("�ݾ��� �Է��Ͻÿ�>>");
		N = scan.nextInt();
		while(true)
		{
			if(N/unit[i]!=0)
			{
				cnt = N/unit[i];
				N= N%unit[i];
			}
			else
			{
				if(cnt!=0)
					System.out.println(unit[i]+"�� ¥�� : "+cnt+"��");
				cnt=0;
				i++;
				if(N==0)
					return;
			}

		}
		
	}

}
