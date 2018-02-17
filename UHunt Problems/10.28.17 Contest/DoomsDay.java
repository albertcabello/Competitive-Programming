import java.util.*;
import java.text.*;
class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int count = scan.nextInt();
		for (int i = 0; i < count; i++) {
			int M = scan.nextInt();
			int D = scan.nextInt();
			Calendar cal = new GregorianCalendar(2011, M-1, D);
			String dayName = cal.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.getDefault());
			System.out.println(dayName);
		}
	}
}
