fun solve() {
    val N = readLine()!!.toInt()
    val AB = mutableListOf<Pair<Int, Int>>()
    val cand = mutableListOf<Int>()
    repeat(N) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        cand.addAll(listOf(a - 1, a, b, b + 1))
        AB.add(a to b)
    }
    
    for (x in cand) {
        var cnt = 0
        for ((a, b) in AB) {
            if (x in a..b) {
                cnt++
            }
        }
        if (cnt == 1) {
            println(x)
            return
        }
    }
    println(-1)
}

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        solve()
    }
}
