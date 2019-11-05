import java.awt.*;
import javax.swing.*;

public class SimpleSwingFrame extends JFrame{
	public SimpleSwingFrame() {
		super("Open Challenge 9"); // Ÿ��Ʋ
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new BorderLayout()); // ����Ʈ���� ����Ʈ�� BorderLayout�̱� ������ �� ������ ��� ��
		
		// �� ���� �г��� ���δ�.
		c.add(new NorthPanel(), BorderLayout.NORTH); // NorthPanel�� �������� NORTH ������ �����Ѵ�.
		c.add(new CenterPanel(), BorderLayout.CENTER); // CenterPanel�� �������� CENTER ������ �����Ѵ�.
		setSize(300,300);
		setVisible(true);
	}
	
	// �������� NORTH ������ �����Ǵ� �г� Ŭ����
	class NorthPanel extends JPanel {
		public NorthPanel() {
			setBackground(Color.LIGHT_GRAY); // ���� ����
			setLayout(new FlowLayout());
			add(new JButton("Open"));
			add(new JButton("Read"));
			add(new JButton("Close"));	
		}
	}

	// �������� CENTER ������ �����Ǵ� �г� Ŭ����
	class CenterPanel extends JPanel {
		public CenterPanel() {
			setLayout(null); // ��ġ������ ����, ���� ��ġ�� ������Ʈ ����
			
			JLabel a = new JLabel("Hello");
			a.setSize(100,20);
			a.setLocation(100, 10); // ���ڿ��� ��ġ ����
			
			JLabel b = new JLabel("Java");
			b.setSize(100,20);
			b.setLocation(20, 150); // ���ڿ��� ��ġ ����
			
			JLabel c = new JLabel("Love");			
			c.setSize(100,20);
			c.setLocation(200, 120); // ���ڿ��� ��ġ ����

			// 3 ���� ���ڿ� ����
			add(a);
			add(b);
			add(c);				
		}		
	}
	
	static public void main(String[] arg) {
		new SimpleSwingFrame();
	}
}
