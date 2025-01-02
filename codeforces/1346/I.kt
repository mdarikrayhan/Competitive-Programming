import kotlin.math.abs

fun main() {
    val INF = 1e9.toInt()
    val INF64 = 1e18.toLong()
    val LOG = 60
    var (n, m, q, s) = readLine()!!.split(' ').map { it.toInt() }
    s--
    val a = readLine()!!.split(' ').map { it.toInt() }
    
    val summask = LongArray(1 shl n) { 0 }
    for (mask in 0 until (1 shl n)) {
        for (i in 0 until n) {
            if ((mask and (1 shl i)) > 0)
                summask[mask] += a[i].toLong()
        }
    }

    val d = Array(n) { IntArray(n) { INF } }
    for (i in 0 until m) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() }
        d[x - 1][y - 1] = 1
    }
    
    val C = readLine()!!.split(' ').map { it.toLong() }

    for (k in 0 until n) {
        for (i in 0 until n) {
            for (j in 0 until n)
                d[i][j] = minOf(d[i][j], d[i][k] + d[k][j])
        }
    }

    val dp = Array(n) { Array(n) { IntArray(1 shl n) { INF } } }
    for (st in 0 until n) {
        dp[st][st][1 shl st] = 0

        for (mask in 0 until (1 shl n)) {
            for (i in 0 until n) {
                if ((mask and (1 shl i)) == 0)
                    continue
                for (j in 0 until n) {
                    if ((mask and (1 shl j)) > 0)
                        continue
                    dp[st][j][mask or (1 shl j)] =
                            minOf(dp[st][j][mask or (1 shl j)], dp[st][i][mask] + d[i][j])
                }
            }
        }
    }

    val bst = Array(n) { LongArray(n * n) { 0 } }
    for (i in 0 until n) {
        for (mask in 0 until (1 shl n)) {
            if ((mask and (1 shl i)) > 0) {
                for (j in 0 until n) {
                    if (dp[i][j][mask] != INF)
                        bst[i][dp[i][j][mask]] = maxOf(bst[i][dp[i][j][mask]], summask[mask])
                }
            }
        }
    }

    val steps = Array(LOG) { Array(n) { LongArray(n) { INF64 } } }
    for (i in 0 until n) {
        for (j in 0 until n)
            steps[0][i][j] = dp[i][j][(1 shl n) - 1].toLong()
    }

    for (t in 1 until LOG) {
        for (i in 0 until n) {
            for (j in 0 until n) {
                for (k in 0 until n)
                    steps[t][i][j] = minOf(steps[t][i][j], steps[t - 1][i][k] + steps[t - 1][k][j])
            }
        }
    }

    for (qr in 0 until q) {
        val sum = summask[(1 shl n) - 1]
        val need = C[qr] / sum

        var cur = LongArray(n) { INF64 }
        cur[s] = 0

        for (t in 0 until LOG - 1) {
            if ((need and (1L shl t)) > 0) {
                val ncur = LongArray(n) { INF64 }
                for (i in 0 until n) {
                    for (j in 0 until n)
                        ncur[i] = minOf(ncur[i], steps[t][j][i] + cur[j])
                }
                cur = ncur
            }
        }

        var ans = INF64
        for(i in 0 until n) {
            val lft = C[qr] % sum
            for (j in 0 until n * n) {
            	if (bst[i][j] >= lft)
            		ans = minOf(ans, cur[i] + j);
            }
        }

        println(ans)
    }
}