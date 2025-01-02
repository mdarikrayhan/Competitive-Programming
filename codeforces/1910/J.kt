fun solve() {
    val N = readLine()!!.toInt()
    val color = readLine()!!.split(" ").map { it.toInt() }

    val G = Array(N) { mutableListOf<Pair<Int, Int>>() }
    repeat(N - 1) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        val aAdjusted = a - 1
        val bAdjusted = b - 1
        G[aAdjusted].add(Pair(bAdjusted, c))
        G[bAdjusted].add(Pair(aAdjusted, c))
    }

    var ANS: Long = 0

    fun dfs(v: Int, p: Int): Pair<Int, Int> {
        var a = 0
        var b = 0
        for ((w, cost) in G[v]) {
            if (w == p) continue
            val (c, d) = dfs(w, v)
            ANS += cost.toLong() * (c + d)
            a += c
            b += d
        }
        if (color[v] == 0) {
            a += 1
        }
        if (color[v] == 1) {
            b += 1
        }
        val k = minOf(a, b)
        a -= k
        b -= k
        return Pair(a, b)
    }

    val (a, b) = dfs(0, -1)
    if (a + b > 0) {
        println("Infinity")
    } else {
        println(ANS)
    }
}

fun main() {
    solve()
}
