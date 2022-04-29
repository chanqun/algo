class Solution {
    fun solution(arr: IntArray): Boolean {
        arr.sort()

        arr.forEachIndexed { index, i ->
            if (index + 1 != i) {
                return false
            }
        }

        return true
    }
}
