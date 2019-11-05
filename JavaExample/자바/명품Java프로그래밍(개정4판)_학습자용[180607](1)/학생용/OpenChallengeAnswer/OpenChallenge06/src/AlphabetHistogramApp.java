import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class AlphabetHistogramApp {
	private int histoData [] = new int [26]; // ���� ���ĺ� 26�ڸ� ī�����ϴ� ������ �迭
	
	public AlphabetHistogramApp() {
		for(int i=0; i<histoData.length; i++)
			histoData[i] = 0; // �ʱ⿡ ī���� ���� ��� 0���� ����
	}
	
	// Ű����κ��� ���ĺ� ���ڸ� �а� ������׷��� �׸��� �ٽ� �޼ҵ�
	public void run() {
		String s = readString();
		makeHistogram(s);
		drawHistogram();
	}
	
	// �Է¹��� ���ڵ�κ��� ������׷��� ����Ÿ�� �����.
	private void makeHistogram(String text) {
		String s = text.toString(); // ��Ʈ�� ������ ���ڿ��� ��Ʈ������ ����
		s = s.toUpperCase(); // ��Ʈ���� ��� �ҹ��ڷ� ����

		// �Էµ� ��� ���ڸ� ���Ͽ� ������ ����Ÿ�� �����.
		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if(c >= 'A' && c <= 'Z') { // ���ĺ� ���ڸ� ī����
				int index = c - 'A';
				histoData[index]++;
			}
		}		
	}

	// ������׷��� �׸���.
	private void drawHistogram() {
		System.out.println("\n������׷��� �׸��ϴ�.");
		for(int i =0; i<histoData.length; i++) {
			System.out.print((char)('A'+ i)); //�빮�ڸ� ����Ѵ�.

			for(int j=0; j<histoData[i]; j++)
				System.out.print('-'); // �����䵥��Ÿ ������ŭ -�� ����Ѵ�.
			System.out.println();			
		}
	}
	
	// Ű����κ��� ���ڿ��� �о� ��Ʈ�� ���ۿ� �����Ѵ�.
	private String readString() {
		System.out.println("���� �ؽ�Ʈ�� �Է��ϰ� �����ݷ��� �Է��ϼ���.");
		StringBuffer sb = new StringBuffer(); // Ű �Է��� ���� ��Ʈ������ ����
		Scanner scanner = new Scanner(System.in);
		while(true) { 
			String line = scanner.nextLine(); // �ؽ�Ʈ �� ������ �д´�.
			if(line.length() == 1 && line.charAt(0)==';')
				break; // �Է� ��
			sb.append(line); // ���� ���� ���ڿ��� ��Ʈ�����ۿ� �߰��Ѵ�.
		} 
		
		scanner.close();
		return sb.toString(); // ��Ʈ�������� ���ڿ��� ��Ʈ������ ����
	}
	
	public static void main(String[] args) {
		AlphabetHistogramApp app = new AlphabetHistogramApp();
		app.run();
	}

}
