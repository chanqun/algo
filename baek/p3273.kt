package practice//import java.io.BufferedReader
//import java.io.InputStreamReader
//import java.util.*
//
//val set = HashSet<Int>()
//val numList = ArrayList<Int>()
//
//fun practice.main() {
//    val br = BufferedReader(InputStreamReader(System.`in`))
//    var answer = 0
//
//    val n = br.readLine().toInt()
//    val st = StringTokenizer(br.readLine())
//
//    for (i in 0 until n) {
//        val num = st.nextToken().toInt()
//        numList.add(num)
//    }
//
//    val x = br.readLine().toInt()
//
//    for (i in 0 until n) {
//        val num = numList[i]
//
//        if (x - num <= 0) {
//            continue
//        }
//
//        if (set.contains(x - num)) {
//            answer++
//        } else {
//            set.add(num)
//        }
//    }
//
//    println(answer)
//}