import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GamblingGameFrame extends JFrame{
	public GamblingGameFrame() {
		super("Open Challenge 10"); // Ÿ��Ʋ
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(new GamePanel()); // GamePanel�� ����Ʈ������ ����Ѵ�. 

		setSize(300,200);
		setVisible(true);
		
		// GamePanel�� Ű �̺�Ʈ�� ���� �� �ֵ��� ��Ŀ���� �����Ѵ�.
		getContentPane().setFocusable(true);
		getContentPane().requestFocus(); 
		
	}
	
	// ����Ʈ���� ���Ǵ� �г� Ŭ����
	class GamePanel extends JPanel {
		private JLabel [] label = new JLabel [3]; // 3 ���� ���� ǥ���ϴ� ���̺� �迭
		private JLabel result = new JLabel("�����մϴ�."); // ����� ����ϴ� ���̺�
		
		public GamePanel() {
			setLayout(null); // ��ġ�����ڸ� ������� �ʰ� ���� ��ġ�� ������Ʈ�� ��ġ�Ѵ�.
			
			// 3 ���� ���̺��� �����Ͽ� �����̳ʿ� �ܴ�.
			for(int i=0; i<label.length; i++) {
				label[i] = new JLabel("0"); // ���̺� ����
				label[i].setSize(60, 30); // ���̺� ũ��
				label[i].setLocation(30+80*i, 50); // ���̺� ��ġ
				label[i].setHorizontalAlignment(JLabel.CENTER); // ���̺� ��µǴ� ���� ���͸�
				label[i].setOpaque(true); // ���̺� ���� ������ �����ϵ��� �Ѵ�.
				label[i].setBackground(Color.MAGENTA); // ���̺��� ������ �����Ѵ�.
				label[i].setForeground(Color.YELLOW); //���̺��� ���� ���� �����Ѵ�.				
				label[i].setFont(new Font("Tahoma", Font.ITALIC, 30)); // ���̺� ������ ��Ʈ�� �����Ѵ�.	
				add(label[i]); // ���̺��� �����Ѵ�.
			}
			
			// ����� ����� ���̺��� �����ϰ� �����̳ʿ� �����Ѵ�.
			result.setSize(200, 20);
			result.setLocation(100, 120);
			add(result);
			
			// Ű �����ʸ� �����Ѵ�.
			addKeyListener(new KeyAdapter() { // KeyAdapter �̿�
				@Override
				public void keyPressed(KeyEvent e) {
					if(e.getKeyChar() == '\n') { //<Enter>Ű�� �Էµ� ���
						int x1 = (int)(Math.random()*5); // 0~4������ ������
						label[0].setText(Integer.toString(x1));
						int x2 = (int)(Math.random()*5);
						label[1].setText(Integer.toString(x2));
						int x3 = (int)(Math.random()*5);
						label[2].setText(Integer.toString(x3));
						
						if(x1 == x2 && x2 == x3) // 3 ���� ������ ��
							result.setText("�����մϴ�!!");
						else
							result.setText("�ƽ�����");
					}
				}
			});
			
			// ���콺�� �����г��� Ŭ���ϸ� ��Ŀ���� ������ ������ ������ �ϱ� ���� ���콺 ������
			addMouseListener(new MouseAdapter() { 
				@Override
				public void mouseClicked(MouseEvent e) {
					Component c = (Component)e.getSource(); // ���콺�� Ŭ���� ������Ʈ
					c.requestFocus(); // ���콺�� Ŭ���� ������Ʈ���� ��Ŀ�� ����
				}
			}); 

		}
	}
	
	static public void main(String[] arg) {
		new GamblingGameFrame();
	}
}
