import java.util.Scanner;

abstract class Shape {
   private Shape next;
   public Shape() { next = null; }
   public void setNext(Shape obj) { next = obj; } // ��ũ ����
   public Shape getNext() { return next; }
   public abstract void draw();
}

class Line extends Shape {
   public void draw() {
      System.out.println("Line");
   }
}
class Rect extends Shape {
   public void draw() {
      System.out.println("Rect");
   }
}
class Circle extends Shape {
   public void draw() {
      System.out.println("Circle");
   }
}
class GraphicEditor{
	private Shape head, tail;
	  
	   
	   Scanner scan = new Scanner(System.in); 
	   public GraphicEditor() {
	      head = null;  // ���� ���
	      tail = null; // �� ���      
	   }
	   
	   public void insert(int draw) { // ��� ����
		      Shape grapic;
		      switch(draw) {
		      case 1:
		         grapic = new Line();
		         break;
		      case 2:
		         grapic = new Rect();
		         break;
		      case 3:
		         grapic = new Circle();
		         break;
		      default:
		         System.out.println("�ٽ� �Է��� �ּ���.");
		         return;
		      }
		      if(head == null) { // head�� �ƹ��͵� ����Ű�� ������
		         head = grapic; // head�� tail�� ���ο� ��带����Ŵ
		         tail = grapic;
		      }
		      else {
		         tail.setNext(grapic); // �� ��忡 ���ο� ��带 �����ϰ�,
		         tail = grapic; // �� ���� ���� ������� ��带 ����Ű�� ��
		      }
		   }
		   public void print() { // ��ü ��� ���
		      Shape s = head;
		      while(s != null) {
		         s.draw();
		         s = s.getNext();
		      }
		   }
		   public void delete(int num) { // num�� ���° �������
		      Shape cur = head; // ���� ���
		      Shape tmp = head;
		      int i;
		      if( num == 1) { // ù��° ��带 �����ϴ� ��� 
		         if(head == tail) { // ��尡 �Ѱ� �ϰ�� 
		            head = null;
		            tail = null;
		            return;
		         }
		         else { // ��尡 �ΰ� �̻�
		            head = head.getNext();
		            return;
		         }
		      }
		      for(i=1; i<num; i++) {
		         tmp = cur; // ���� ��带 ���� ��  (��, ���� ���)
		         cur = cur.getNext(); // ���� ���� �̵�
		         if(cur == null) { // ��� ���� �Է� ������ ������
		            System.out.println("������ �� �����ϴ�.");
		            return;
		         }
		      }
		      if(i==num) { // �� ��带 ����ų��
		         tmp.setNext(cur.getNext());
		         tail = tmp;
		      }
		      else // ����尡 �ƴ϶�� ������尡 ���� ��带 ����Ŵ (��, ���� ��� ����)
		         tmp.setNext(cur.getNext());
		   }
	   
	   
	   public void run() {
	      System.out.println("�׷��� ������ beauty�� �����մϴ�.");
	      while(true) {
	         System.out.print("����(1), ����(2), ��� ����(3), ����(4) >> ");
	         int operation = scan.nextInt();
	         switch(operation) {
	         case 1:
	            System.out.print("Line(1), Rect(2), Circle(3) >> ");
	            operation = scan. nextInt();
	            insert(operation);
	            break;
	         case 2:
	            System.out.print("������ ������ ��ġ >> ");
	            operation = scan.nextInt();
	            delete(operation);
	            break;
	         case 3:
	            print();
	            break;
	         case 4:
	            System.out.println("beauty�� �����մϴ�.");
	            scan.close();
	            return;
	         }
	      }
	   }
}

public class Ex12{   
   
   public static void main(String[] args) {
      // TODO Auto-generated method stub
	   GraphicEditor No = new GraphicEditor();
         No.run();
   }
}