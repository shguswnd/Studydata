package ch04;

import java.util.Scanner;

class Dictionary{
	private static String[] kor = {"���","�Ʊ�","��","�̷�","���"};
	private static String[] eng = {"love","baby","money","future","hope"};
	public static String kor2eng(String word)
	{
		for(int i=0;i<kor.length;i++)
		{
			if(word.equals(kor[i]))
				return eng[i];
			
				
				
		}
		return "x";
		
	}
}

public class Ex10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String en;
		Scanner scan = new Scanner(System.in);
		Dictionary D = new Dictionary();
		while(true)
		{

			System.out.print("�ѱ� �ܾ�?");
			String name = scan.next();
		
			if(name.equals("�׸�"))
				return;
			en = D.kor2eng(name);
			if(en !="x")
			System.out.println(name+"��" + en);
			else if(en=="x")
				System.out.println(name +"�� ���� ������ �����ϴ�.");
				
		}
	}

}
