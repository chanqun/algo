package solution;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.stream.Stream;

public class template {
	public static Queue<Integer> queue = new LinkedList<>();
	public static Stack<Integer> stack = new Stack<>();
	public static ArrayList<Integer> array = new ArrayList<>();
	public static ArrayList<ArrayList<Integer>> array2 = new ArrayList<>();
	public static PriorityQueue<Integer> priorityQueue = new PriorityQueue<Integer>();
	public static PriorityQueue<Integer> reversePriorityQueue = new PriorityQueue<>(Collections.reverseOrder());
	public static HashMap<String, Integer> hashMap = new HashMap<>();
	public static String[] sArray = { "hello", "apple", "banana" };
	public static ArrayList<Node> nodeArray = new ArrayList<>();

	static class Node implements Comparable<Node> {
		int y;
		int x;

		Node(int y, int x) {
			this.y = y;
			this.x = x;
		}

		@Override
		public int compareTo(Node node) {
			if (this.x > node.x) {
				return 1; // x에 대해서는 오름차순
			} else if (this.x == node.x) {
				if (this.y < node.y) {
					return 1; //y에 대하여 내림차순
				}
			}
			return -1;
		}

		@Override
		public String toString() {
			return "Node [y=" + y + ", x=" + x + "]";
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] firstLine = br.readLine().split(" ");
		for (String string : firstLine) {
			System.out.println(string);
		}
		
		Node n1 = new Node(4, 3);
		System.out.println(n1.toString());

		nodeArray.add(new Node(1, 7));
		nodeArray.add(new Node(2, 4));
		nodeArray.add(new Node(3, 4));
		nodeArray.add(new Node(4, 1));
		nodeArray.add(new Node(4, 7));
		
		Collections.sort(nodeArray);
		System.out.println(nodeArray);
		
		System.out.println("queue");
		queue.add(3);
		queue.add(4);
		System.out.println(queue.remove());
		System.out.println(queue.element());

		System.out.println("stack");
		stack.add(4);
		stack.add(5);
		System.out.println(stack.pop());
		System.out.println(stack.peek());

		System.out.println("array");
		array.add(6);
		array.add(3);
		System.out.println(array.size());
		array.add(4);
		array.add(5);
		System.out.println(array.size());
		System.out.println(array.get(2));
		array.remove(2);
		System.out.println(array.size());

		Collections.sort(array);
		System.out.println(array.toString());

		System.out.println("2차원 arrayList");
		for (int i = 0; i < 3; i++) {
			array2.add(new ArrayList<Integer>());
		}
		System.out.println(array2.size());

		System.out.println("priorityqueue : " + priorityQueue.peek());
		priorityQueue.add(3);
		priorityQueue.add(2);

		hashMap.put("hello", 1);
		int a = hashMap.get("hello");
		hashMap.replace("hello", a + 1);
		System.out.println("hashMap : " + hashMap.get("hello"));
		hashMap.remove("hello");
		System.out.println("hashMap : " + hashMap.get("hello"));

		System.out.println(Integer.MAX_VALUE);
		Arrays.sort(sArray);
		System.out.println(sArray[0] + sArray[1]);
	}
}
