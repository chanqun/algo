class Solution {
    fun solution(grade: IntArray): Int {
        var answer = 0

        for (index in 0 until grade.size - 1) {
            var newIndex = grade.size - index - 1

            if (grade[newIndex - 1] > grade[newIndex]) {
                answer += grade[newIndex - 1] - grade[newIndex]
                grade[newIndex - 1] = grade[newIndex]
            }
        }

        return answer
    }
}
