package ch03;

public class Ex12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int sum =0;
		for(int i=0;i<args.length;i++)
		{
			sum += Integer.parseInt(args[i]);
			try {
				
			}catch(NumberFormatException e)
			{
				continue;
			}
		}
		System.out.println(sum);
	}

}
