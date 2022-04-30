import java.util.*

class Solution {
    val pq = PriorityQueue<Int>(Collections.reverseOrder())

    fun solution(no: Int, works: IntArray): Int {
        var answer = 0

        works.forEach {
            pq.add(it)
        }

        repeat(no) {
            val num = pq.poll()

            val newNum = if (num <= 0) {
                0
            } else {
                num - 1
            }

            pq.add(newNum)
        }

        while (!pq.isEmpty()) {
            val num = pq.poll()

            answer += (num * num)
        }

        return answer
    }
}

fun main() {
    val N = 2
    val works = intArrayOf(3, 3, 3)

    val result = Solution4().solution(N, works)

    println(result)
}
