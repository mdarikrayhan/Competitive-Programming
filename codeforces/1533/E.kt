fun main() {
	val n = readLine()!!.toInt()
	val a = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
	val b = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
	val m = readLine()!!.toInt()
	val c = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
	a.sort()
	b.sort()
	val pr = IntArray(n + 1) { -2e9.toInt() }
	for (i in 0 until n) {
		pr[i + 1] = maxOf(pr[i], b[i] - a[i])
	}
	val su = IntArray(n + 1) { -2e9.toInt() }
	for (i in (n-1) downTo 0) {
		su[i] = maxOf(su[i + 1], b[i + 1] - a[i])
	}
	val ans = IntArray(m)
	for (i in 0 until m) {
		var pos = a.binarySearch(c[i])
		if (pos < 0) {
			pos = -pos - 1
		}
		ans[i] = maxOf(pr[pos], su[pos], b[pos] - c[i])
	}
	println(ans.joinToString(" "))
}