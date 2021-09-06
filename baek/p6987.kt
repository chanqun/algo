import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val array = Array(10) { IntArray(10) }

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    for (i in 0 until 4) {
        val st = StringTokenizer(br.readLine())
        var column = 0

        for (j in 0 until 18) {
            val num = st.nextToken().toInt()

            array[column / 3][column % 3] = num
            column++
        }

        print("${isPossible()} ")
    }
}

private fun isPossible(): Int {
    var win = 0
    var draw = 0
    var drawTeam = 0
    var lose = 0

    for (i in 0 until 6) {
        win += array[i][0]
        draw += array[i][1]
        lose += array[i][2]

        if (array[i][1] != 0) {
            drawTeam++
        }
    }

    if (draw % 2 != 0 || win != lose || drawTeam % 2 != 0) {
        return 0
    }

    return 1
}
