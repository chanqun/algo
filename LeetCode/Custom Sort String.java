class Solution {
	public String customSortString(String S, String T) {
		StringBuilder solution = new StringBuilder();

		int[] charCheck = new int[26];

		for (char temp : T.toCharArray()) {
			charCheck[temp - 'a']++;
		}

		for (char temp : S.toCharArray()) {
			while (charCheck[temp - 'a']-- > 0) {
				solution.append(temp);
			}
		}

		for (char temp = 'a'; temp <= 'z'; temp++) {
			while (charCheck[temp - 'a']-- > 0) {
				solution.append(temp);
			}
		}

		return solution.toString();
	}
}