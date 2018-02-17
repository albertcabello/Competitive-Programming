import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a, friendCount, count = 1;
        a = scan.nextInt();
        friendCount = scan.nextInt();
        while (a != 0 && friendCount != 0) {
            BigInteger sum = BigInteger.ZERO;
            for (int i = 0; i < a; i++) {
                String item = scan.next();
                sum = sum.add(new BigInteger(item));
                //System.out.println(sum);
            }
            BigInteger div = sum;
            div = div.divide(new BigInteger(friendCount + ""));
            System.out.printf("Bill #%d costs %s: each friend should pay %s\n\n", count, sum.toString(), div.toString());
            count++;
            a = scan.nextInt(); friendCount = scan.nextInt();
        }

    }
}
