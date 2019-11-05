package ch03;

import java.util.Scanner;

public class Ex14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String course[] = {"Java","C++","HTML5","컴퓨터구조","안드로이드"};
		int score[] = {95,88,76,62,55};
		Scanner scan = new Scanner(System.in);
		
		String no;
		
		while(true)
		{
			System.out.print("과목이름>>");
			no = scan.next();
			if(no.equals("그만"))
				return;
			for(int i=0;i<course.length;i++)
			{
				if(course[i].equals(no))
				{
					System.out.println(course[i]+"의 점수는"+score[i]);
					break;
				}
				else
				{
					System.out.println("없는 과목입니다.");
					break;
				}
			}
		}
	}

}
