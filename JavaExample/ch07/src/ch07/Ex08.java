package ch07;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class Ex08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		HashMap<String, Integer> manage = new HashMap<String, Integer>();
		System.out.println("** 포인트 관리 프로그램입니다 **");
		while(true) {
			System.out.print("이름과 포인트 입력 >> ");
			String name = scan.next();
			if(name.equals("그만"))
				break;
			int point = scan.nextInt();
			if(manage.get(name)==null) {
				manage.put(name,point);
			}
			else {//중복이름이 있을때
				manage.put(name, manage.get(name)+point);
			}
			Set<String>key = manage.keySet();
			Iterator<String> it = key.iterator();
			while(it.hasNext()) {
				String people = it.next();
				Integer sum = manage.get(people);
				System.out.print("(" + people+","+sum+")");
			}
			System.out.println();
		}
		scan.close();
	}

}
