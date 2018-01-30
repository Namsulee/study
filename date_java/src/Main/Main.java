package Main;

class Main {
	public static void main(String Args[]) {
		StringBuffer obj;
		obj = new StringBuffer("Hey, Java");
		obj.deleteCharAt(1);
		obj.deleteCharAt(1);
		obj.insert(1, 'i');
		System.out.println(obj);
	}
}