import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var practice.getArray = Array(0) { IntArray(0) }
var check = Array(0) { BooleanArray(0) }
val dy = intArrayOf(-1, 0, 1, 0)
val dx = intArrayOf(0, 1, 0, -1)
var N = 0
var M = 0

fun practice.main() {

    val br = BufferedReader(InputStreamReader(System.`in`))

    var st = StringTokenizer(br.readLine())

    N = st.nextToken().toInt()
    M = st.nextToken().toInt()

    practice.getArray = Array(N) { IntArray(M) }
    check = Array(N) { BooleanArray(M) }

    for (i in 0 until N) {
        val str = br.readLine()

        for (j in 0 until M) {
            val num = Character.getNumericValue(str[j])
            practice.getArray[i][j] = num
        }
    }

    val result = bfs()

    println(result)
}

fun bfs(): Int {
    val queue: Queue<Point> = LinkedList()
    queue.add(Point(0, 0, 1))
    check[0][0] = true

    while (!queue.isEmpty()) {
        val (y, x, count) = queue.poll()

        for (i in 0 until 4) {
            val dy = y + dy[i]
            val dx = x + dx[i]

            if (dy == N - 1 && dx == M - 1) {
                return count + 1
            }

            if (dy < 0 || dx < 0 || dy >= N || dx >= M || practice.getArray[dy][dx] == 0 || check[dy][dx]) continue

            check[dy][dx] = true
            queue.add(Point(dy, dx, count + 1))
        }
    }
    return 0
}

data class Point(
    val y: Int,
    val x: Int,
    val count: Int
)
