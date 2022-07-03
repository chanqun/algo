class Solution {
    fun solution(n: Int, horizontal: Boolean): Array<IntArray> {
        var answer: Array<IntArray> = Array(n) { IntArray(n) { 0 } }
        var number = 1

        var count = 0

        for (i in 0 until n) {

            for (j in 0..count) {
                answer[j][i] = number++
            }

            for (j in 0 until count) {
                answer[i][count - j - 1] = number++
            }

            count++
        }

        val div = when (horizontal) {
            true -> 0
            false -> 1
        }

        for (i in 0 until n) {
            for (j in 0..i) {
                if (i % 2 == div) {
                    var temp = answer[j][i]

                    answer[j][i] = answer[i][j]
                    answer[i][j] = temp
                }
            }
        }

        return answer
    }
}

