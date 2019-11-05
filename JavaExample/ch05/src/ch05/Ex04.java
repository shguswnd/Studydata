package ch05;
import java.util.Scanner;
abstract class Converter {
   abstract protected double convert(double src); // �߻� �޼ҵ�
   abstract protected String getSrcString(); // �߻� �޼ҵ�
   abstract protected String getDestString(); // �߻� �޼ҵ�
   protected double ratio; // ����
   public void run() {
      Scanner scanner = new Scanner(System.in);
      System.out.println(getSrcString()+"�� "+getDestString()+"�� �ٲߴϴ�.");
      System.out.print(getSrcString()+"�� �Է��ϼ���>> ");
      double val = scanner.nextDouble();
      double res = convert(val);
      System.out.println("��ȯ ���: "+res+getDestString()+"�Դϴ�");
      scanner.close();
   }
}
class Km2Mile extends Converter{
	Km2Mile(double ratio){
		this.ratio = ratio;
	}

	@Override
	protected double convert(double src) {
		// TODO Auto-generated method stub
		return src/ratio;
	}

	@Override
	protected String getSrcString() {
		// TODO Auto-generated method stub
		return "Km";
	}

	@Override
	protected String getDestString() {
		// TODO Auto-generated method stub
		return "mile";
	}
}
public class Ex04 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Km2Mile toMile = new Km2Mile(1.6);
		toMile.run();
	}

}
