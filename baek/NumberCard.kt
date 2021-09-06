import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val numbers = arrayListOf<Int>()

fun practice.main() {

    val br = BufferedReader(InputStreamReader(System.`in`))

    val n = br.readLine().toInt()


    var st = StringTokenizer(br.readLine())
    for (i in 1..n) {
        val number = st.nextToken().toInt()

        numbers.add(number)
    }

    numbers.sort()

    val m = br.readLine().toInt()

    st = StringTokenizer(br.readLine())

    for (i in 1..m) {
        val checkNum = st.nextToken().toInt()

        val isInclude = binarySearch(checkNum)

        if (isInclude) {
            print("1 ")
        } else {
            print("0 ")
        }
    }
}

fun binarySearch(checkNum: Int): Boolean {
    var first = 0
    var last = numbers.size - 1
    var mid = 0

    while (first <= last) {

        mid = (first + last) / 2

        if (checkNum == numbers[mid]) {
            return true
        } else if (checkNum < numbers[mid]) {
            last = mid - 1
        } else {
            first = mid + 1
        }
    }

    return false
}