class Solution {
	public int maxDepth(TreeNode root) {
		return checkDepth(root, 0);
	}

	public int checkDepth(TreeNode node, int depth) {
		if (node == null) {
			return depth;
		}

		return Math.max(checkDepth(node.left, depth + 1), checkDepth(node.right, depth + 1));
	}
}