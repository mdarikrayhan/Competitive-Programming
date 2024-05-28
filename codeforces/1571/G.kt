class Attack(val a: Int, val b: Int, val i: Int)

fun main() {
	val (n, m) = readLine()!!.split(" ").map { it.toInt() }
	val ev = ArrayList<Attack>()

	for (i in 0 until n) {
		val k = readLine()!!.toInt()
		val a = readLine()!!.split(" ").map { it.toInt() }
		val b = readLine()!!.split(" ").map { it.toInt() }
		for (j in 0 until k) {
			ev.add(Attack(a[j], b[j], i))
		}
	}
	ev.sortWith(compareBy({ -it.b }, { it.i }))
	
	val INF = 1e18.toLong()
	val mx = m + n + 1
	val f = LongArray(mx) { -INF }
	
	fun update(pos: Int, x: Long) {
		var i = pos
		while (i < mx) {
			f[i] = maxOf(f[i], x)
			i = i or (i + 1)
		}
	}
	
	fun query(pos: Int) : Long {
		var res = -INF
		var i = pos
		while (i >= 0) {
			res = maxOf(res, f[i])
			i = (i and (i + 1)) - 1
		}
		return res
	}
	
	update(m - 1, 0L)
	for (it in ev) {
		val dp = query(it.i + it.b - 1) + it.a
		update(it.i + it.b, dp)
	}
	println(query(mx - 1))
}