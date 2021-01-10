import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int answer = Integer.MAX_VALUE;

		int x = sc.nextInt();
		int y = sc.nextInt();
		int w = sc.nextInt();
		int h = sc.nextInt();

		answer = Math.min(Math.abs(x), Math.abs(w - x));
		answer = Math.min(answer, Math.min(y, h - y));

		System.out.println(answer);
	}
}