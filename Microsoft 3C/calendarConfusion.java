import java.util.*;
import java.io.*;
import java.text.*;

class Main {
	public static void main(String[] args) throws ParseException, IOException {
		String current, given, desired;
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			current = scan.next(); given = scan.next(); desired = scan.next();
			DateFormat org = new SimpleDateFormat(given);
			DateFormat target = new SimpleDateFormat(desired);
			Date date = org.parse(current);
			String ans = target.format(date);
			System.out.println(ans);
		}
	}
}


