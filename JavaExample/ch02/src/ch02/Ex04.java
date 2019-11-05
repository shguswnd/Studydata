package ch02;
import java.util.Scanner;
public class Ex04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a,b,c;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("정수 3개 입력>>>");
		
		a = scan.nextInt();
		b = scan.nextInt();
		c = scan.nextInt();
		
		if((a>b)&&(a>c))
		{
			if(b>c)
				System.out.println("중간값은 "+b);
			else
				System.out.println("중간값은 "+c);
		}
		else if((b>a)&&(b>c))
		{
			if(a>c)
				System.out.println("중간값은 "+a);
			else
				System.out.println("중간값은 "+c);
		
		}
		else if((c>b)&&(c>a))
		{
			if(b>a)
				System.out.println("중간값은 "+b);
			else
				System.out.println("중간값은 "+a);
		
		}
	}

}
