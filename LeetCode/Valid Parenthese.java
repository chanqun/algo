class Solution {
	private HashMap<Character, Character> mappings;

	public Solution() {
		mappings = new HashMap<Character, Character>();
		mappings.put(')', '(');
		mappings.put(']', '[');
		mappings.put('}', '{');
	}

	public boolean isValid(String s) {
		Stack<Character> stack = new Stack<>();

		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);

			if (mappings.containsKey(c)) {
				char topChar = stack.empty() ? 'X' : stack.pop();

				if (topChar != mappings.get(c)) {
					return false;
				}
			} else {
				stack.push(c);
			}
		}

		return stack.isEmpty();
	}
}