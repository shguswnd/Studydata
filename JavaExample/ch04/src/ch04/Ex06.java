package ch04;

import java.util.Scanner;

class Circle{
	private double x,y;
	private int radius;
	public Circle(double x, double y, int radius) {
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	public void show()
	{
		System.out.println("가장 면적이 큰 원은 x, y, radius >>>" +x+" "+y+" "+" "+radius);
	}
	
}

public class Ex06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Circle c[] = new Circle[3];
		int max = 0;
		int maxi=0;
		for(int i=0;i<c.length;i++)
		{
			System.out.print("x,y, radius >>>");
			double x = scan.nextDouble();
			double y = scan.nextDouble();
			int radius = scan.nextInt();
			c[i] = new Circle(x, y, radius);
			if(i==0)
			{
				max = radius;
				maxi = i;
			}if(i>0)
			{
				if(max<radius)
				{
					max = radius;
					maxi = i;
				}
			}
		}
		
		/*for(int i=0;i<c.length;i++)
			c[i].show();
		*/
		c[maxi].show();
		scan.close();
		
		
	}

}
