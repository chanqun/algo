val coins = listOf(1.0, 5.0, 10.0, 50.0, 100.0, 500.0)

class Solution {
    fun solution(money: Int, costs: IntArray): Int {
        var answer: Int = 0

        var result = ArrayList<Triple<Double, Double, Int>>()

        costs.forEachIndexed { index, cost ->
            val coin = coins[index]

            val createCost: Double = cost / coin

            result.add(Triple(createCost, coin, cost))
        }

        result.sortBy { it.first }

        var nowMoney = 0

        while (true) {
            result.forEach {
                val coin = it.second
                
                val mul = (money - nowMoney) / coin.toInt()

                answer += it.third * mul
                nowMoney += it.second.toInt() * mul
            }

            if (nowMoney == money) {
                break
            }
        }

        return answer
    }
}
