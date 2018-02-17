import java.util.*;
import java.math.*;
class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int count = scan.nextInt();
		while (scan.hasNext()) {
			for (int i = 0; i < count; i++) {
				scan.nextLine();
				int kids = scan.nextInt();
				BigInteger sum = BigInteger.ZERO;
				for (int j = 0; j < kids; j++) {
					sum = sum.add(scan.nextBigInteger());
				}
				if (sum.mod(new BigInteger(kids + "")) == BigInteger.ZERO) {
					System.out.println("YES");
				}
				else {
					System.out.println("NO");
				}
			}
		}
	}
}
