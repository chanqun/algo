import java.util.ArrayList;

class Solution {
	public int[][] map;
	public int[][] map2;
	public ArrayList<Integer> array = new ArrayList<>();

	public int[] solution(int rows, int columns, int[][] queries) {
		int[] answer = {};
		map = new int[rows + 1][columns + 1];
        map2 = new int[rows + 1][columns + 1];

		int mapNumber = 1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				map[i][j] = mapNumber;
				map2[i][j] = mapNumber;
				mapNumber++;
			}
		}

		query(queries, rows, columns);

		answer = new int[array.size()];
		for (int i = 0; i < answer.length; i++) {
			answer[i] = array.get(i);
		}
		return answer;
	}

	public void query(int[][] queries, int rows, int columns) {
		for (int i = 0; i < queries.length; i++) {
			int x1, y1, x2, y2;
			int minNumber = Integer.MAX_VALUE;
			x1 = queries[i][0] - 1;
			y1 = queries[i][1] - 1;
			x2 = queries[i][2] - 1;
			y2 = queries[i][3] - 1;

			int temp = map[x1][y2];
			if (temp < minNumber) {
				minNumber = temp;
			}

			for (int j = y2; j > y1; j--) {
				map[x1][j] = map[x1][j - 1];
				if (map[x1][j - 1] < minNumber) {
					minNumber = map[x1][j - 1];
				}
			}

			for (int j = x1; j < x2; j++) {
				map[j][y1] = map[j + 1][y1];
				if (map[j + 1][y1] < minNumber) {
					minNumber = map[j + 1][y1];
				}
			}

			for (int j = y1; j < y2; j++) {
				map[x2][j] = map[x2][j + 1];
				if (map[x2][j + 1] < minNumber) {
					minNumber = map[x2][j + 1];
				}
			}

			for (int j = x2; j > x1; j--) {
				map[j][y2] = map[j - 1][y2];
				if (map[j - 1][y2] < minNumber) {
					minNumber = map[j - 1][y2];
				}
			}

			map[x1 + 1][y2] = temp;

			array.add(minNumber);
		}
	}
}
