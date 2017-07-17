import java.math.*;
import java.io.*;
import java.util.*;
class Main {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(new File("test.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter(new File("output.txt")));
		out.write(scan.nextBigInteger(8).toString(16).toUpperCase());
	}
}
