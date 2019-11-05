package ch07;
import java.util.HashMap;
import java.util.Iterator;//��ü������ �ݺ����
import java.util.Scanner;
import java.util.Set;//����. ��Ҵ� �ߺ��ɼ����� ������ �������ְ� ���ĵɼ�����.
import java.util.StringTokenizer;//���ڿ��κ��� ��ū�� ��������.

class Location{
	private String city;
	private double longitude; // �浵
	private double latitude; // ����
	public String getcity() {return city;}
	public double getlongitude() {return longitude;}
	public double getlatitude() {return latitude;}
	public Location(String city, double longitude,double latitude) {
		this.city = city;
		this.longitude = longitude; //�浵
		this.latitude = latitude; //����
	}
}

public class Ex06 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Location[] location = new Location[4];
		HashMap<String,Location> manage = new HashMap<String, Location>();
		System.out.println("����, �浵, ������ �Է��ϼ���.");
		for(int i=0; i<location.length; i++) {
			System.out.print(">>");
			String text = scan.nextLine();
			StringTokenizer st = new StringTokenizer(text,",");//,���� ��ū���� ����.
			String city = st.nextToken().trim(); //��ū���� �ؽ�Ʈ ���ְ� trim���� ���� ����.
			int longitude = Integer.parseInt(st.nextToken().trim());
			int latitude = Integer.parseInt(st.nextToken().trim());
			location[i] = new Location(city,longitude,latitude);
			manage.put(city, location[i]);//�ؽ��� Ű�� ���÷� ������ �־���.
		}
		Set<String> key = manage.keySet();//Ű���� ��������.
		Iterator<String> it = key.iterator();
		System.out.println("----------------------------------");
		while(it.hasNext()) {
			String city = it.next();
			Location s = manage.get(city);//������ Ű���� ����.
			System.out.println(s.getcity() +" "+s.getlongitude()+" "+s.getlatitude());
		}
		while(true) {
			System.out.print("���� �̸� >> ");
			String city = scan.next();
			if(city.equals("�׸�"))
				break;
			Location s = manage.get(city);//������ Ű���� ����.
			if(s==null)
				System.out.println(city+"�� �����ϴ�.");
			else
			System.out.println(s.getcity() +" "+s.getlongitude()+" "+s.getlatitude());
		}
		scan.close();
		
		
	}

}
