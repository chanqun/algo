class Solution {
	public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>> answer = new ArrayList<List<Integer>>();
		helper(0, nums, answer);
		return answer;
	}

	private void helper(int start, int[] nums, List<List<Integer>> answer) {
		if (start == nums.length - 1) {
			List<Integer> list = new ArrayList<Integer>();
			for (int num : nums) {
				list.add(num);
			}
			answer.add(list);
			return;
		}

		for (int i = start; i < nums.length; i++) {
			swap(nums, i, start);
			helper(start + 1, nums, answer);
			swap(nums, i, start);
		}
	}

	private void swap(int[] nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
}