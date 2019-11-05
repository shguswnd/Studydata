package ch04;

import java.util.Scanner;

class Phone{
	String name;
	int tel;
	
	public Phone(String name, int tel)
	{
		this.name  = name;
		this.tel = tel;
	}
	
}
public class Ex08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
				
		System.out.print("인원수 >>");
		int N = scan.nextInt();
		
		Phone p[] = new Phone[N];
		for(int i=0;i<p.length;i++)
		{
			System.out.print("이름과 전화번호(이름과 번호는 빈 칸없이 입력)>>");
			String name = scan.next();
			int tel = scan.nextInt();
			
			p[i] = new Phone(name,tel);
		}
		System.out.println("저장되었습니다...");
		while(true)
		{
			int cnt =0;
			System.out.print("검색할 이름>>>");
			String name = scan.next();
		
			if(name.equals("그만"))
				return;
			for(int i=0;i<p.length;i++)
			{
				
				if(name.equals(p[i].name))
				{
						System.out.println(p[i].name + "번호는 "+p[i].tel +" 입니다.");
						cnt--;
						break;
				}
				cnt++;
			}
			if(cnt==p.length)
				System.out.println("검색한 이름이 없음.");
		
				
		}
		
		
	}

}
