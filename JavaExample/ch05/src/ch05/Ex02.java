package ch05;

class ColorTV{
	public int inch,color;
	ColorTV(int inch, int color) {
	  this.inch = inch;
	  this.color = color;
	}
				
}
class IPTV extends ColorTV{
	private String ip;
	
	IPTV(String string,int inch,int color)
	{
		super(inch,color);
		this.ip = string;
	}
	void printProperty()
	{
	    System.out.print("���� IPTV�� "+ip+"�ּ��� "+ inch+"��ġ "+color+"�÷�");
	}
}

public class Ex02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IPTV ip = new IPTV("192,1,12",32,2048);
		ip.printProperty();
	}

}
