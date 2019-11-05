package ch04;

import java.util.Scanner;

class Dictionary{
	private static String[] kor = {"사랑","아기","돈","미래","희망"};
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

			System.out.print("한글 단어?");
			String name = scan.next();
		
			if(name.equals("그만"))
				return;
			en = D.kor2eng(name);
			if(en !="x")
			System.out.println(name+"은" + en);
			else if(en=="x")
				System.out.println(name +"는 저의 사전에 없습니다.");
				
		}
	}

}
