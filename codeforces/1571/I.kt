import java.util.*

fun main() = repeat(readLine()!!.toInt()) {
	val n = readLine()!!.toInt()
	val L = readLine()!!.split(" ").map { it.toInt() }
	val R = readLine()!!.split(" ").map { it.toInt() }
	
	val ord = Array(n, { i -> i })
	ord.sortWith({x : Int, y: Int -> L[x] - L[y]})
	
	val ans = IntArray(n)
	
	fun check(u: Int): Int {
		val cur = PriorityQueue<Int>(compareBy { R[it] })
		var uu = 0
		var res =0
		for (i in 1 until n + 1) {
			while (uu<n && L[ord[uu]] <= u+i-1) {
				cur.add(ord[uu])
				++uu;
			}
			if (cur.isEmpty()) {
				res = 1
				break
			}
			if (R[cur.peek()] < u+i-1) {
				res = -1
				break
			}
			ans[i - 1] = cur.peek() + 1
			cur.poll()
		}
		return res;
	}
	
	var l = 0
	var r = 1000000001
	var res = 0
	while (r-l>1) {
		val m = (l + r) / 2
		val tmp = check(m)
		if (tmp == 0) {
			println(m)
			println(ans.joinToString(" "))
			res = 1
			break
		}
		if (tmp == -1) {
			r = m
		}
		else {
			l = m
		}
	}
	
	if (res == 0) {
		println(-1)
	}
}
					        		   	 				  	