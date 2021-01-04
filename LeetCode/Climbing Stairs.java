class Solution {
	public int climbStairs(int n) {
		int[] count = new int[n + 1];
		count[0] = 0;
		count[1] = 1;
		count[2] = 2;
		count[3] = 3;

		for (int i = 4; i <= n; i++) {
			count[i] = count[i - 1] + count[i - 2];
		}

		return count[n];
	}
}