package ch07;
import java.util.ArrayList;
import java.util.Scanner;
public class Ex02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Character> stack = new ArrayList<Character>();//char Ÿ���� Ŭ��������
		Scanner scan = new Scanner(System.in);
		System.out.print("6���� ������ �� ĭ���� �и� �Է�(A/B/C/D/F) >> ");
	
		for(int i=0;i<6;i++) {
			char c = scan.next().charAt(0);//ù��������
			stack.add(c);
		}
		int sum=0;
		for(int i=0;i<stack.size();i++) {
			char c = stack.get(i);
			switch(c) {
			case 'A':
				sum+=4;
				break;
			case 'B':
				sum+=3;
				break;
			case 'C':
				sum+=2;
				break;
			case 'D':
				sum+=1;
				break;
			case 'F':
				sum+=0;
				break;
			}
		}
		double avr = (double)sum/stack.size();
		System.out.println(avr);
		scan.close();
	}

}
