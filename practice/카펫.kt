class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = intArrayOf()

        val candidate = mutableListOf<Int>()

        for (i in 1..yellow) {
            if (yellow % i == 0) {
                candidate.add(i)
            }
        }

        candidate.forEach {
            val row = it
            val col = yellow / it

            if ((row + 2) * (col + 2) == brown + yellow) {
                answer = intArrayOf(row + 2, col + 2)
                return@forEach
            }
        }

        return answer
    }
}
