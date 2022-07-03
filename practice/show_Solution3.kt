import java.util.LinkedList
import java.util.Queue

class Solution {
    val dy = listOf(-1, 0, 1, 0)
    val dx = listOf(0, 1, 0, -1)

    fun solution(rows: Int, columns: Int, lands: Array<IntArray>): IntArray {
        var map = Array(rows + 2) { IntArray(columns + 2) { 0 } }
        var maxLand = -1
        var minLand = Int.MAX_VALUE

        lands.forEach {
            val y = it[0]
            val x = it[1]

            map[y][x] = 1
        }

        val firstQueue: Queue<Data> = LinkedList()
        firstQueue.add(Data(0, 0))
        map[0][0] = -1

        while (!firstQueue.isEmpty()) {
            val (y, x) = firstQueue.poll()

            for (i in 0 until 3) {
                val dy: Int = y + dy[i]
                val dx = x + dx[i]

                if (dy < 0 || dx < 0 || dy >= rows || dx >= columns) continue
                if (map[dy][dx] != 0) continue

                map[dy][dx] = -1
                firstQueue.add(Data(dy, dx))
            }
        }

        for (i in (1 until rows - 1)) {
            for (j in (1 until columns - 1)) {
                print("${map[i][j]}")
            }
            println()
        }

        for (i in (1 until rows - 1)) {
            for (j in (1 until columns - 1)) {
                var lake = 1
                if (map[i][j] != 0) continue

                val queue: Queue<Data> = LinkedList()
                queue.add(Data(i, j))
                map[i][j] = 2

                while (!queue.isEmpty()) {
                    val (y, x) = queue.poll()
                    for (k in 0 until 3) {
                        val dy = y + dy[k]
                        val dx = x + dx[k]

                        if (dy < 0 || dx < 0 || dy >= rows || dx >= columns) continue
                        if (map[dy][dx] != 0) continue

                        map[dy][dx] = 2
                        queue.add(Data(dy, dx))
                        lake++
                    }
                }

                if (maxLand < lake) {
                    maxLand = lake
                }

                if (minLand > lake) {
                    minLand = lake
                }
            }
        }

        if (maxLand == -1) {
            minLand = -1
        }

        return intArrayOf(minLand, maxLand)
    }
}

data class Data(
    val y: Int,
    val x: Int
)
