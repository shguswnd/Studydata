package ch07;
import java.util.HashMap;
import java.util.Iterator;//객체지향의 반복기법
import java.util.Scanner;
import java.util.Set;//집합. 요소는 중복될수없고 순서가 있으수있고 정렬될수있음.
import java.util.StringTokenizer;//문자열로부터 토큰을 추출해줌.

class Location{
	private String city;
	private double longitude; // 경도
	private double latitude; // 위도
	public String getcity() {return city;}
	public double getlongitude() {return longitude;}
	public double getlatitude() {return latitude;}
	public Location(String city, double longitude,double latitude) {
		this.city = city;
		this.longitude = longitude; //경도
		this.latitude = latitude; //위도
	}
}

public class Ex06 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Location[] location = new Location[4];
		HashMap<String,Location> manage = new HashMap<String, Location>();
		System.out.println("도시, 경도, 위도를 입력하세요.");
		for(int i=0; i<location.length; i++) {
			System.out.print(">>");
			String text = scan.nextLine();
			StringTokenizer st = new StringTokenizer(text,",");//,마다 토큰으로 나눔.
			String city = st.nextToken().trim(); //토큰들을 넥스트 해주고 trim으로 공백 삭제.
			int longitude = Integer.parseInt(st.nextToken().trim());
			int latitude = Integer.parseInt(st.nextToken().trim());
			location[i] = new Location(city,longitude,latitude);
			manage.put(city, location[i]);//해쉬에 키값 도시로 값들을 넣어줌.
		}
		Set<String> key = manage.keySet();//키들의 집합저장.
		Iterator<String> it = key.iterator();
		System.out.println("----------------------------------");
		while(it.hasNext()) {
			String city = it.next();
			Location s = manage.get(city);//지정된 키값을 리턴.
			System.out.println(s.getcity() +" "+s.getlongitude()+" "+s.getlatitude());
		}
		while(true) {
			System.out.print("도시 이름 >> ");
			String city = scan.next();
			if(city.equals("그만"))
				break;
			Location s = manage.get(city);//지정된 키값을 리턴.
			if(s==null)
				System.out.println(city+"는 없습니다.");
			else
			System.out.println(s.getcity() +" "+s.getlongitude()+" "+s.getlatitude());
		}
		scan.close();
		
		
	}

}
