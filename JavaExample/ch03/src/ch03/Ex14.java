package ch03;

import java.util.Scanner;

public class Ex14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String course[] = {"Java","C++","HTML5","��ǻ�ͱ���","�ȵ���̵�"};
		int score[] = {95,88,76,62,55};
		Scanner scan = new Scanner(System.in);
		
		String no;
		
		while(true)
		{
			System.out.print("�����̸�>>");
			no = scan.next();
			if(no.equals("�׸�"))
				return;
			for(int i=0;i<course.length;i++)
			{
				if(course[i].equals(no))
				{
					System.out.println(course[i]+"�� ������"+score[i]);
					break;
				}
				else
				{
					System.out.println("���� �����Դϴ�.");
					break;
				}
			}
		}
	}

}
