package ch07;
import java.util.Vector;
import java.util.Scanner;
public class Ex04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Integer>stack = new Vector<Integer>();//Integer �ΰ� ó�� ���� ��ڽ��� ��������.
		Scanner scan = new Scanner(System.in);
		while(true) {
			System.out.print("������ �Է� (0 �Է½� ����) >> ");
			int num = scan.nextInt();
			if(num==0)
				break;
			stack.add(num);
			int avr = 0;
			for(int i=0;i<stack.size();i++) {
				System.out.print(stack.get(i)+" ");
				avr += stack.get(i);
			}
			System.out.println();
			avr/=stack.size();
			System.out.println("���� ��� "+avr);
		}
		scan.close();
	}
}
