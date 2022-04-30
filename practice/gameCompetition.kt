class Solution {
    fun solution(n: Int, a: Int, b: Int): Int {
        var answer = 1

        var na = a
        var nb = b

        while (checking(na, nb)) {
            val (nna, nnb) = makeNextNum(na, nb)
            na = nna
            nb = nnb
            
            answer += 2
        }
        
        return answer
    }

    private fun checking(na: Int, nb: Int): Boolean {
        val checkA = when (na % 2 == 0) {
            true -> na
            false -> na + 1
        }

        val checkB = when (nb % 2 == 0) {
            true -> nb
            false -> nb + 1
        }

        return checkA == checkB
    }

    private fun makeNextNum(na: Int, nb: Int): Pair<Int, Int> {
        val checkA = when (na % 2 == 0) {
            true -> na
            false -> na + 1
        }

        val checkB = when (nb % 2 == 0) {
            true -> nb
            false -> nb + 1
        }

        return Pair(checkA / 2, checkB / 2)
    }
}
