package ch04;

import java.util.Scanner;

class Grade{
	private int math, science, english;
	
	Grade(int math,int science, int english){
		this.math = math;
		this.science = science;
		this.english = english;
	}
	public double average()
	{
		return (math+science+english)/3.0;
	}
}
public class Ex02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.println("����, ����, ���� ������ 3���� ���� �Է�");
		int math = scan.nextInt();
		int science = scan.nextInt();
		int english = scan.nextInt();
		Grade me = new Grade(math, science, english);
		System.out.println("����� " + me.average());
		
	
	}

}
