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
		System.out.println("** ����Ʈ ���� ���α׷��Դϴ� **");
		while(true) {
			System.out.print("�̸��� ����Ʈ �Է� >> ");
			String name = scan.next();
			if(name.equals("�׸�"))
				break;
			int point = scan.nextInt();
			if(manage.get(name)==null) {
				manage.put(name,point);
			}
			else {//�ߺ��̸��� ������
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
