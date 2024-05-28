fun main() {
    repeat(readInt()) {
        val (n, k) = readInts()
        val g = List(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readInts().map { it - 1 }
            g[a].add(b)
            g[b].add(a)
        }
        val size = IntArray(n)
        fun dfs(v: Int, p:Int) : Int {
            size[v] = 1 + g[v].sumOf { if (it == p) 0 else dfs(it, v) }
            return size[v]
        }
        dfs(0, 0)
        val ns = size.map { it.toLong() * (n - it) }.sortedDescending()
        println(ns.subList(0, k - 1).sum() + ns.subList(k - 1, ns.size).sum() * 2)
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }