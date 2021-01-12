import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
	private static Queue<Integer> priorityQueue = new PriorityQueue<Integer>(Collections.reverseOrder());

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			int temp = Integer.parseInt(br.readLine());

			if (temp == 0) {
				Integer answer = priorityQueue.poll();
				if (answer == null) {
					System.out.println(0);
				} else {
					System.out.println(answer);
				}
			} else {
				priorityQueue.add(temp);
			}
		}
	}
}
