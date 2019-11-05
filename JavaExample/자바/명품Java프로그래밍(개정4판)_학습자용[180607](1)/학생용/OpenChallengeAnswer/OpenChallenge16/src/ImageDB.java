import java.io.*;
import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ImageDB extends JFrame implements ActionListener {
	private JMenuItem save, view, exit;
	private JFileChooser fc;
	private Statement stmt = null;
	private Connection conn = null;
	private JMenuBar menuBar;
	private JMenu menu;
	private int numberOfRecord;
	private JLabel imageLabel;
	private JLabel textLabel;
	private JButton nextButton;
	private ResultSet viewRS=null;
	private ImageIcon img=null;
	
	public ImageDB() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/photodb", "root","1234"); // JDBC ����
			stmt = conn.createStatement(); // SQL�� ó���� Statement ��ü ����
			ResultSet srs;
			srs = stmt.executeQuery("select count(*) from images"); // ���ڵ� ������ ������ ����
			srs.next();
			numberOfRecord = srs.getInt(1);
		} catch (ClassNotFoundException e) {
			handleError(e.getMessage());
		} catch (SQLException e) {
			handleError(e.getMessage());
		}
		
		setTitle("�̹��� ������ ���̽�"); // ������ Ÿ��Ʋ
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //������ ���� ��ư(X)�� Ŭ���ϸ� ���α׷� ����
		
		Container c = getContentPane();
		
		c.setLayout(new BorderLayout()); //BorderLayout ��ġ�������� ���
		fc = new JFileChooser(); // JFileChooser ��ü ����
		menuBar = new JMenuBar(); // JMenuBar ������Ʈ�� ����
		menu = new JMenu("�޴�");
		menuBar.add(menu); // �޴��� �޴��ٿ� ���δ�

		// ���� �޴�
		save = new JMenuItem("���� ����");
		save.addActionListener(this); // save �޴��� ���� �̺�Ʈ �����ʸ� ���
		menu.add(save); // �޴� �������� �޴��� ���δ�
		view = new JMenuItem("��� ���� ����");
		menu.add(view); // �޴� �������� �޴��� ���δ�
		view.addActionListener(this); // view �޴��� ���� �̺�Ʈ �����ʸ� ���
		menu = new JMenu("����");
		exit = new JMenuItem("������");
		exit.addActionListener(this); // exit �޴��� ���� �̺�Ʈ �����ʸ� ���
		menu.add(exit); // �޴� �������� �޴��� ���δ�
		menuBar.add(menu); // �޴��� �޴��ٿ� ���δ�
		setJMenuBar(menuBar); // �޴��ٸ� �����ӿ� ���δ�
		
		imageLabel = new JLabel(); // �̹����� ǥ���� ���̺� ������Ʈ
		imageLabel.setHorizontalAlignment(SwingConstants.CENTER); // �߾�����
		textLabel = new JLabel(); // ���� �̸��� ǥ���� ���̺� ������Ʈ
		textLabel.setHorizontalAlignment(SwingConstants.CENTER); // �߾�����
		nextButton = new JButton("���� ����"); // ���� ���� ���⸦ ���� ��ư
		nextButton.addActionListener(this); // ��ư�� ���� �̺�Ʈ �����ʸ� ���
		JScrollPane spane = new JScrollPane(imageLabel); // ū �������� �̹����� ����  ScrollPane���� ǥ��
		c.add(textLabel,BorderLayout.NORTH);
		c.add(spane,BorderLayout.CENTER);
		JPanel panel = new JPanel();
		panel.setSize(50,50); // ��ư ũ��
		panel.add(nextButton);
		c.add(panel,BorderLayout.SOUTH);
		
		setSize(400, 400); // �� 400 �ȼ�, ���� 400 �ȼ��� ũ��� ������ ũ�� ����
		setVisible(true); // �������� ȭ�鿡 ��Ÿ������ ����
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == exit) { // ����
			System.exit(0);
		} else if (e.getSource() == save) { // ������ DB�� �߰�
			int returnVal = fc.showOpenDialog(this); // ���� ���� ���̾�α� ���
			if (returnVal == JFileChooser.APPROVE_OPTION) { // ���� ��ư�� ���� ���
				insertImage(fc.getSelectedFile()); // ������ ������ ����
			}
		}
		else if (e.getSource() == view) { // ���� ����
			showPhotos();
		} else if (e.getSource() == nextButton) { // ���� ���� ��ư
			try {
				if (viewRS == null || !viewRS.next()) { // �� ������ ���� ���
					imageLabel.setIcon(null);
					imageLabel.setText("���� ����");
					textLabel.setText(null);
				} else {
					Blob b = viewRS.getBlob("FILE"); // DB���� ���̳ʸ� ������ ����
					img = new ImageIcon(b.getBytes(1, (int) b.length())); // ���̳ʸ� �����͸� �̹��� �������� ��ȯ
					imageLabel.setIcon(img);
					imageLabel.setText(null);
					textLabel.setText(viewRS.getString("FILENAME")); // ���� �̸��� textLabel�� ���
				}
			} catch (SQLException e1) {
				handleError(e1.getMessage());
			}
		}
	}
	
	private void showPhotos() {
		try {
			viewRS = stmt.executeQuery("select * from images"); // DB���� ��� ������ ����
			if (viewRS.next()) { // ù��° ���� ǥ��
				Blob b = viewRS.getBlob("FILE"); // DB���� ���̳ʸ� ������ ����
				img = new ImageIcon(b.getBytes(1, (int) b.length())); // ���̳ʸ� �����͸� �̹��� �������� ��ȯ
				imageLabel.setIcon(img);
				imageLabel.setText(null);
				textLabel.setText(viewRS.getString("FILENAME")); // ���� �̸��� textLabel�� ���
			} else { // DB�� ������ ���� ���
				imageLabel.setIcon(null);
				imageLabel.setText("���� ����");
				textLabel.setText(null);
			}
		} catch (SQLException e) {
			handleError(e.getMessage());
		}
	}

	private static void handleError(String string) {
		System.out.println(string);
		System.exit(1);
	}
	
	private void insertImage(File file) {
        try{
            FileInputStream fin = new FileInputStream(file); // ���� �Է� ��Ʈ�� ����
            PreparedStatement pre = conn.prepareStatement("insert into images (ID, FILENAME, FILE) VALUES (?, ?, ?)");
            pre.setInt(1,numberOfRecord++);
            pre.setString(2,file.getName());
            pre.setBinaryStream(3,fin,(int)file.length());
            pre.executeUpdate(); // DB�� ���� ����
            pre.close(); 
        } catch (Exception e){
            handleError(e.getMessage());
        }
	}

	public static void main(String[] args) {
		ImageDB frame = new ImageDB();
	}
}
