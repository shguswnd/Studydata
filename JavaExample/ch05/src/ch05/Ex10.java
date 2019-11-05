
abstract class PairMap {
   protected String KeyArray[]; // key ���� �����ϴ� �迭
   protected String valueArray[]; // value ���� �����ϴ� �迭
   abstract String get(String key); // key ���� ���� value ����, ������ null ����
   abstract void put(String ket, String value); // key�� value�� ������ ����. ������ key�� ������, ���� value�� ����
   abstract String delete(String key); // key ���� ���� ������ (value�� �Բ�) ����, ������ value �� ����
   abstract int length(); // ���� ����� �������� ���� ����
}

class Dictionary extends PairMap {
	int cnt=0;
	   public Dictionary(int num) {
		   KeyArray = new String[num];
	      valueArray = new String[num];
	   }
	   
	   public String get(String key) {
	      for(int i=0; i<length(); i++) {
	         if(key.equals(KeyArray[i])) {
	            return valueArray[i];
	         }
	      }
	      return null; // ���ϴ� key�� ���ٸ� null ����
	   }
	   public void put(String key, String value) {
		   for(int i=0;i<length();i++)
		   {
			   if(key.equals(KeyArray[i]))
	            {
				   valueArray[i] = value;
				   return;
	            }
			}
		   KeyArray[cnt] = key;
		   valueArray[cnt] = value;
		   cnt++;
	   }
	
	   
	   public String delete(String key) {
	      for(int i=0; i<length(); i++) {
	         if(key.equals(KeyArray[i])) {
	            String value = valueArray[i];
	            KeyArray[i] = null;
	            valueArray[i] = null;
	            return value;  // ������ value �� ����
	         }
	      }
	      return null; // ������ ���� ���ٸ� null ����
	   }
	   public int length() {
	      return cnt;
	   }
	}
public class Ex10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	      Dictionary dic = new Dictionary(10);
	      dic.put("Ȳ����", "�ڹ�");
	      dic.put("���繮", "���̼�");
	      dic.put("���繮", "C++"); // ���繮�� ���� C++�� ����
	      System.out.println("���繮�� ���� "+dic.get("���繮"));
	      System.out.println("Ȳ������ ���� "+dic.get("Ȳ����"));
	      dic.delete("Ȳ����"); // Ȳ���� ������ ����
	      System.out.println("Ȳ������ ���� "+dic.get("Ȳ����")); //������ ������ ����
	}

}
