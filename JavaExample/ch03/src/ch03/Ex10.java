package ch03;


public class Ex10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[][] = new int[4][4];
		int cnt=0;
		int x,y;
		
		
		while(cnt<10)//10개의 배열에 값을 넣어주기 위함.
		{
			x = (int)(Math.random()*4);//배열을 랜덤에게 줌.
			y = (int)(Math.random()*4);
			if(arr[x][y]==0)//값이 없을경우만 배열에 랜덤변수 삽입
			{
				arr[x][y] = (int)(Math.random()*10+1);
				cnt++;
			}
			//if밖이면 배열에 값이 있는 경우이므로 반복돌림.
		}
		
		for(int i=0;i<arr.length;i++)//출력.
		{
			for(int j=0;j<arr[i].length;j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
