package ch07;
import java.util.Vector;
import java.util.Scanner;
public class Ex04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Integer>stack = new Vector<Integer>();//Integer 널값 처리 용이 언박싱을 하지않음.
		Scanner scan = new Scanner(System.in);
		while(true) {
			System.out.print("강수량 입력 (0 입력시 종료) >> ");
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
			System.out.println("현재 평균 "+avr);
		}
		scan.close();
	}
}
