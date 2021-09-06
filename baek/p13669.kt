import java.io.BufferedReader
import java.io.InputStreamReader

var N = 0
var practice.getArray = Array<Long>(36) { 0 }

fun practice.main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    N = br.readLine().toInt()

    practice.getArray[0] = 1
    practice.getArray[1] = 1

    for (i in 2..N) {

        for (j in 0 until i) {
            practice.getArray[i] += practice.getArray[(i - 1) - j] * practice.getArray[j]
        }
    }

    println(practice.getArray[N])
}

