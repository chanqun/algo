import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun practice.main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var queue: Queue<Pizza> = LinkedList()

    val N = br.readLine().toInt()

    var stringToken = StringTokenizer(br.readLine())

    for (i in 0 until N) {
        val M = stringToken.nextToken().toInt()

        val pizza = Pizza(i, 0, M)
        queue.add(pizza)
    }

    var time = 0
    var answerList = IntArray(N) { 0 }
    while (!queue.isEmpty()) {
        time++
        var nowPizza = queue.poll()

        if (nowPizza.eat + 1 == nowPizza.want) {
            answerList[nowPizza.index] = time
        } else {
            nowPizza = Pizza(nowPizza.index, nowPizza.eat + 1, nowPizza.want)
            queue.add(nowPizza)
        }
    }

    answerList.forEach {
        print("$it ")
    }
}

data class Pizza(
    var index: Int,
    var eat: Int,
    var want: Int
)

