package ch03;

import java.util.Scanner;

public class Ex16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str[] = {"가위","바위","보"};
		String no;
		Scanner scan = new Scanner(System.in);
		System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
		
		while(true)
		{
			int n = (int)(Math.random()*3);
			
			System.out.print("가위 바위 보!!>>");
			no  = scan.next();
			if(no.equals("그만"))
				return;
			System.out.print("사용자 = " + no + " , 컴퓨터 = "+str[n]+", ");
			
			if(str[n].equals(no))
				System.out.println("비겼습니다.");
			else if(str[n].equals("가위"))
			{
				if(no.equals("바위"))
					System.out.println("이겼습니다.");
				else if(no.equals("보"))
					System.out.println("졌습니다.");
			}
			else if(str[n].equals("바위"))
			{
				if(no.equals("보"))
					System.out.println("이겼습니다.");
				else if(no.equals("가위"))
					System.out.println("졌습니다.");
			}
			else if(str[n].equals("보"))
			{
				if(no.equals("가위"))
					System.out.println("이겼습니다.");
				else if(no.equals("바위"))
					System.out.println("졌습니다.");
			}
		}
	}

}
