import java.util.*

class Solution {
    private val arrayList = arrayListOf<ArrayList<Node>>()
    lateinit var checkList: Array<Int>

    fun solution(N: Int, road: Array<IntArray>, k: Int): Int {
        var answer = 0

        (0..N).forEach { _ -> arrayList.add(arrayListOf()) }
        checkList = Array(N + 1) { -1 }

        road.forEach {
            val i = it[0]
            val j = it[1]
            val distance = it[2]

            arrayList[i].add(Node(j, distance))
            arrayList[j].add(Node(i, distance))
        }

        answer = bfs(1, k)

        return answer
    }

    private fun bfs(i: Int, k: Int): Int {
        val queue: Queue<Node> = LinkedList()

        var count = 1
        checkList[i] = 0
        queue.add(Node(i, 0))

        while (!queue.isEmpty()) {
            val (num, beforeDistance) = queue.poll()

            for (nextNode in arrayList[num]) {
                val (nextNum, distance) = nextNode
                val totalDistance = beforeDistance + distance

                if (checkList[nextNum] <= totalDistance && totalDistance <= k) {
                    queue.add(Node(nextNum, totalDistance))

                    if (checkList[nextNum] == -1) {
                        count++
                    }

                    checkList[nextNum] = totalDistance
                }
            }
        }

        return count
    }

    data class Node(
        val to: Int,
        val distance: Int
    )
}
