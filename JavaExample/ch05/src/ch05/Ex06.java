package ch05;

class Point {
	   private int x, y;
	   public Point(int x, int y) { this.x = x; this.y = y; }
	   public int getX() { return x; }
	   public int getY() { return y; }
	   protected void move(int x, int y) { this.x =x; this.y = y; }
	}
class ColorPoint extends Point{

	String color = "BLACK";
	public ColorPoint()
	{
		super(0,0);
	}
	public ColorPoint(int x, int y) {
		super(x, y);//슈퍼는 생성자만 가능.
	}
	public String toString()
	{
		
		return color+"색의 ("+ getX()+","+getY()+")점";
	}
	public void setXY(int x, int y) {
		move(x,y);
	}
	public void setColor(String color){
		this.color = color;
	}
	
}
public class Ex06 {

	public static void main(String[] args) {
		ColorPoint zeroPoint = new ColorPoint(); // (0,0) 위치의 BLACK 색 점
		   System.out.println(zeroPoint.toString() + "입니다.");
		   ColorPoint cp = new ColorPoint(10, 10); // (10,10) 위치의 BLACK 색 점
		   cp.setXY(5,5);
		   cp.setColor("RED");
		   System.out.println(cp.toString()+"입니다.");
	}

}
