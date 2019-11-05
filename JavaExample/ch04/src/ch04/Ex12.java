import java.util.Scanner;



class reservation{
	
	String [][] position = new String[3][10];
	String name;//이름
	int num;//자리 위치.
	int pos;//행위치.
	public reservation()
	{
		for(int i=0;i<position.length;i++)//좌석배열 초기화
		{
			for(int j=0;j<position[i].length;j++)
			{
				position[i][j] = "---";
			}
		}
	}
	
	public void Print(int pos)
	{
		this.pos = pos-1;//행의값을 -1하여 배열위치를 같게함.
		if(pos == 1)//행의위치를 입력받아 해당행 이름출력
			System.out.print("S>>");
		else if(pos == 2)
			System.out.print("A>>");
		else if(pos == 3)
			System.out.print("B>>");
		
		for(int i=0;i<position[this.pos].length;i++)//입력받은 행의 열을 출력.
		{
			System.out.print(position[this.pos][i]+" ");
		}
		System.out.println();
			
	}
	public void Cancel(String name,int pos)
	{
		this.name = name;
		this.pos = pos-1;//행의값을 -1하여 배열위치를 같게함.
		
		for(int i=0;i<position[this.pos].length;i++)
		{
			if(position[this.pos][i].equals(name))//좌석에 이름을 찾을경우 ---초기화 해줌.
				{
					position[this.pos][i] = "---";
				}
		}
		
	}
	public void Input(String name,int num)
	{
		this.name = name;
		this.num = num-1;
		if(position[this.pos][this.num]=="---")//빈자리 일때만 변수저장.
			position[this.pos][this.num] = this.name;
		else
			System.out.println("자리가 없습니다.!!!");
	}
	public void AllPrint()
	{
		for(int i=1;i<4;i++)//Print 메소드호출을 하여 좌석들의 내용들을 출력.
			Print(i);
		System.out.println("조회를 완료하였습니다.>>>");
	}

}


public class Ex12 {

	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int Oper;
		int reserOp;
		String name;
		int num;
		
		reservation Reser= new reservation();
		
		Scanner scan = new Scanner(System.in);
		System.out.println("명품콘서트홀 예약 시스템입니다.");
		while(true)
		{	
			System.out.print("예약:1, 조회:2, 취소:3, 끝내기:4>>");
			Oper = scan.nextInt();
			
			switch(Oper)
			{
				case 1:
					System.out.print("좌석구분 S(1), A(2), B(3)>>");
					reserOp = scan.nextInt();
					Reser.Print(reserOp);//선택된 좌석 출력.
					
					System.out.print("이름>>");
					name = scan.next();
					System.out.print("번호>>");
					num = scan.nextInt();
					Reser.Input(name, num);//삽입 메소드.
					break;
				case 2:
					Reser.AllPrint();//조회메소드.
					break;
				case 3:
					System.out.print("좌석구분 S(1), A(2), B(3)>>");
					reserOp = scan.nextInt();
					Reser.Print(reserOp);
					System.out.print("이름>>");					
					name = scan.next();
					Reser.Cancel(name,reserOp);//취소메소드
					break;
				case 4://시스템 종료
					scan.close();
					System.out.println("프로그램 종료");
					return;
				default:
					System.out.println("잘못 되었으니 다시 입력 해주세요.");
			}
		}
	}

}
