import kotlin.math.min
 private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }
 data class Edge(val u: Int, val c: Int, var f: Int) {
    lateinit var rev: Edge
}
 lateinit var g: List<MutableList<Edge>>
lateinit var dt: MutableList<Int>
lateinit var pos: MutableList<Int>
var n = 0
 fun add(u: Int, v: Int, c: Int) {
    g[u].add(Edge(v, c, 0))
    g[v].add(Edge(u, 0, 0))
    g[u].last().rev = g[v].last()
    g[v].last().rev = g[u].last()
}
 fun bfs(source: Int, dest: Int): Int? {
    dt.fill(n)
    dt[source] = 0
    val q = ArrayDeque<Int>()
    q.addLast(source)
    q.forEach { v ->
        for (e in g[v])
            if (e.f < e.c && dt[e.u] == n) {
                dt[e.u] = dt[v] + 1
                q.add(e.u)
            }
    }
    return dt[dest].takeIf { it < n }
}
 fun dfs(v: Int, dest: Int, cf: Int): Int? {
    if (v == dest)
        return cf
    while (pos[v] < g[v].size) {
        val e = g[v][pos[v]++]
        if (dt[e.u] == dt[v] + 1 && e.c > e.f) {
            dfs(e.u, dest, min(cf, e.c - e.f))?.let { res ->
                e.f += res
                e.rev.f -= res
                return res
            }
        }
    }
    return null
}
 fun dinitz(source: Int, dest: Int): Int {
    return generateSequence { bfs(source, dest) }.map {
        pos.fill(0)
        generateSequence { dfs(source, dest, 1) }.sum()
    }.sum()
}
 fun main() {
    val (nn, m, k) = readInts()
    n = nn + m + 2
    val fg = List(nn) { mutableListOf<Int>() }
    g = List(n) { mutableListOf() }
    dt = MutableList(n) { 0 }
    pos = MutableList(n) { 0 }
    repeat(m) {
        val (u, v) = readInts().map { it - 1 }
        fg[u].add(v)
        fg[v].add(u)
    }
    val q = ArrayDeque<Int>()
    val d = MutableList(nn) { nn }
    d[0] = 0
    q.addLast(0)
    var maxv = nn
    val source = maxv++
    val dest = maxv++
    q.forEach { v ->
        for (u in fg[v]) {
            if (d[u] == nn) {
                d[u] = d[v] + 1
                q.addLast(u)
            } else if (d[u] != d[v] + 1)
                continue
            if (d[v] % 2 == 0) {
                add(maxv, v, 1)
                add(maxv, u, 1)
                add(source, maxv++, 1)
            } else {
                add(u, maxv, 1)
                add(v, maxv, 1)
                add(maxv++, dest, 1)
            }
        }
    }
    println(min(dinitz(source, dest), k))
}