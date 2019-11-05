package ch07;
import java.util.Scanner;
import java.util.Vector;

abstract class Shape{
	private Shape next;
	public Shape() {next =null;};
	public void setNext(Shape obj) {next = obj;}
	public Shape getNext() {return next;}
	public abstract void draw();
}
class Line extends Shape{

	@Override
	public void draw() {
		// TODO Auto-generated method stub
		System.out.println("Line");
	}
	
}
class Circle extends Shape{

	@Override
	public void draw() {
		// TODO Auto-generated method stub
		System.out.println("Circle");
	}
	
}
class Rect extends Shape{

	@Override
	public void draw() {
		// TODO Auto-generated method stub
		System.out.println("Rect");
	}
	
}
public class Ex10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Vector<Shape> v = new Vector<Shape>();
		Shape shape = null; //빈껍데기를 만듬 Object클래스에서 사용해보자.
		System.out.println("그래픽 에디터 beauty을 실행합니다.");
		while(true) {
			System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> ");
			int select = scan.nextInt();
			switch(select) {
			case 1:
				System.out.print("Line(1), Rect(2), Circle(3) >> ");
				int choice = scan.nextInt();
				switch(choice) {
				case 1:
					shape = new Line();
					break;
				case 2:
					shape = new Rect();
					break;
				case 3:
					shape = new Circle();
					break;
				}
				v.add(shape);
				break;
			case 2:
				System.out.print("삭제할 도형의 위치 >> " );
				int position = scan.nextInt();
				if(v.size()==0||v.size()<=position)
					System.out.println("삭제할 수 없습니다.");
				else
					v.remove(position);
				break;
			case 3:
				for(int i=0;i<v.size();i++)
					v.get(i).draw();
				break;
			case 4:
				System.out.println("beauty을 종료합니다.");
				scan.close();
				return;
			}
		}
	}

}
