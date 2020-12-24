class Solution {
	public int minSteps(String s, String t) {
		int[] arr1 = new int[26];
		int[] arr2 = new int[26];

		for (int i = 0; i < s.length(); i++) {
			int temp = (int) s.charAt(i) - 'a';
			int temp2 = (int) t.charAt(i) - 'a';

			arr1[temp]++;
			arr2[temp2]++;
		}

		int answer = s.length();

		for (int i = 0; i < 26; i++) {
			answer -= Math.min(arr1[i], arr2[i]);
		}

		return answer;
	}
}