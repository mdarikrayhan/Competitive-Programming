private fun solve() {
	val n = readInt()
	val flag = readInts()
	val want = readInts()
	val changed = flag.zip(want) { a, b -> a != b }
	val nei = List(n) { mutableListOf<Int>() }
	repeat(n - 1) {
		val (a, b) = readInts().map { it - 1 }
		nei[a].add(b)
		nei[b].add(a)
	}
	val w = changed.indexOfFirst { it }
	if (w == -1) return println("Yes\n0")
	val p = MutableList(n) { 0 }
	val u = dfs(nei, p, changed, w, -1).second
	val v = dfs(nei, p, changed, u, -1).second
	val path = mutableListOf(v)
	while (path.last() != u) path.add(p[path.last()])
	println(check(flag, want, path) ?: check(flag, want, path.reversed()) ?: "No")
}

private fun check(flag: List<Int>, want: List<Int>, path: List<Int>): String? {
	val f = flag.toMutableList()
	val save = f[path.first()]
	for ((a, b) in path.zipWithNext()) {
		f[a] = f[b]
	}
	f[path.last()] = save
	return "Yes\n${path.size}\n${path.map { it + 1 }.joinToString(" ")}".takeIf { f == want }
}

private fun dfs(nei: List<List<Int>>, p: MutableList<Int>, cool: List<Boolean>, v: Int, parent: Int): Pair<Int, Int> {
	var best = if (cool[v]) 0 to v else -nei.size to -1
	p[v] = parent
	for (u in nei[v].minus(parent)) {
		val (dist, vertex) = dfs(nei, p, cool, u, v)
		if (dist + 1 > best.first) best = dist + 1 to vertex
	}
	return best
}

fun main() = repeat(readInt()) { solve() }

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
