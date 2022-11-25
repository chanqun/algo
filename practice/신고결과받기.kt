class Solution {
    fun solution(id_list: Array<String>, report: Array<String>, k: Int): IntArray {
        val reportMap = mutableMapOf<String, MutableSet<String>>()
        var answerMap = mutableMapOf<String, Int>()

        id_list.forEach {
            reportMap[it] = mutableSetOf()
            answerMap[it] = 0
        }

        report.forEach {
            val (user, target) = it.split(" ")

            val set = reportMap[target]!!
            set.add(user)
        }

        val stopList = id_list.filter {
            val reportCount = reportMap[it]!!.size

            reportCount >= k
        }

        id_list.forEach { id ->
            stopList.forEach {
                if (reportMap[it]!!.contains(id)) {
                    answerMap[id] = answerMap[id]!! + 1
                }
            }
        }

        return answerMap.values.toIntArray()
    }
}
