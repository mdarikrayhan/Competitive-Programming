val MOD = 998244353

fun main() {
	val (n, k, c) = readLine()!!.split(' ').map { it.toInt() }
	val t = readLine()!!
	val cnt = n / k + 1
	val dp = Array(2) { IntArray(cnt) {0} }
	val pw = IntArray(cnt) {1}
	dp[0][0] = 1
	for (ii in 0 until n % k) {
		val i = ii and 1
		val ni = i xor 1
		var sum = 0
		val cur = c - (t[ii].toInt() - 'a'.toInt()) - 1
		var pr = 1
		for (j in 1 until cnt) {
			pw[j] = (pw[j - 1] * (cur + 1).toLong() % MOD).toInt()
		}
		for (j in 0 until cnt) {
			sum = ((sum * cur.toLong() + pr * dp[i][j].toLong()) % MOD).toInt()
			pr = (pr * c.toLong() % MOD).toInt()
			dp[ni][j] = (sum * pw[cnt - j - 1].toLong() % MOD).toInt()
		}
	}
	var ans = 0
	for (i in 0 until cnt) {
		ans = (ans + dp[n % k % 2][i]) % MOD
	}
	for (i in 0 until n) {
		if (i % k >= n % k) {
			ans = (ans * c.toLong() % MOD).toInt()
		}
	}
	println(ans)
}