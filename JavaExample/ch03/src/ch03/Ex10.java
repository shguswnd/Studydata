package ch03;


public class Ex10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[][] = new int[4][4];
		int cnt=0;
		int x,y;
		
		
		while(cnt<10)//10���� �迭�� ���� �־��ֱ� ����.
		{
			x = (int)(Math.random()*4);//�迭�� �������� ��.
			y = (int)(Math.random()*4);
			if(arr[x][y]==0)//���� ������츸 �迭�� �������� ����
			{
				arr[x][y] = (int)(Math.random()*10+1);
				cnt++;
			}
			//if���̸� �迭�� ���� �ִ� ����̹Ƿ� �ݺ�����.
		}
		
		for(int i=0;i<arr.length;i++)//���.
		{
			for(int j=0;j<arr[i].length;j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
