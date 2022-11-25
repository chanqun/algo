import kotlin.math.sqrt

class Solution {
    fun solution(number: Int, limit: Int, power: Int): Int {
        var answer: Int = 0

        val list = (1..number).map {
            getDivideNumber(it)
        }.toList()

        list.forEach {
            answer += if (it > limit) {
                power
            } else {
                it
            }
        }

        return answer
    }

    private fun getDivideNumber(number: Int): Int {
        var divideNumber = 0

        (1..sqrt(number.toDouble()).toInt()).forEach {
            if (number % it == 0) {
                if (number / it == it) {
                    divideNumber++
                } else {
                    divideNumber += 2
                }
            }
        }

        return divideNumber
    }
}
