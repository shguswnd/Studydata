package ch02;

import java.util.Scanner;

public class Ex08 {

	public static boolean inRect(int x1, int y1, int x2,int y2)
	{
		if((x1>=100 && y1>=100)&&(x2<=200&&y2<=200))
				return true;
		else
			return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x1,x2,y1,y2;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("두점을 입력하시오");
		x1 = scan.nextInt();
		x2 = scan.nextInt();
		y1 = scan.nextInt();
		y2 = scan.nextInt();
		
		if(inRect(x1, y1, x2, y2))
			System.out.println("사각형이 충돌안한다");
		else
			System.out.println("사각형이 충돌한다");
		
	}

}
