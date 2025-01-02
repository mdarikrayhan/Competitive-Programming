const val mod = 998244353L
fun power(a : Long, r : Long) : Long{
    var res = 1L
    var va = a
    var vr = r
    while (vr > 0) {
        if (vr % 2 == 1L) res = res * va % mod
        va = va * va % mod
        vr /= 2L
    }
    return res
}
fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val (n, a, b) = readInts()
    val xyp = Array(n){readInts()}
    val x = xyp.map { it[0] }.toIntArray()
    val y = xyp.map { it[1] }.toIntArray()
    val p = xyp.map { it[2].toLong() * power(1000000L, mod - 2) % mod }
    var pp = LongArray(a + b + 1){1L}
    var pm = LongArray(a + b + 1){1L}
    for (i in 0 until n) {
        pp[x[i] + y[i]] = pp[x[i] + y[i]] * (mod + 1 - p[i]) % mod
        pm[x[i] - y[i] + b] = pm[x[i] - y[i] + b] * (mod + 1 - p[i]) % mod
    }
    pp = pp.map { (1L + mod - it) % mod }.toLongArray()
    pm = pm.map { (1L + mod - it) % mod }.toLongArray()
    val sx = (x + intArrayOf(0, a)).distinct().sorted()
    val sy = (y + intArrayOf(0, b)).distinct().sorted()
    var ans = 0L
    for (i in 1 until sx.size)
        for (j in 1 until sy.size) {
            ans = (ans + 1L) % mod
            val lx = sx[i - 1]
            val rx = sx[i]
            val ly = sy[j - 1]
            val ry = sy[j]
            for (p in lx + ly + 1 until rx + ry)
                ans = (ans + pp[p]) % mod
            for (m in lx - ry + 1 until rx - ly)
                ans = (ans + pm[m + b]) % mod
            for (p in lx + ly + 1 until rx + ry)
                for (m in lx - ry + 1 until rx - ly){
                        if (p + m in (lx * 2 + 1) until rx * 2 && p - m in (ly * 2 + 1) until ry * 2)
                            ans = (ans + pp[p] * pm[m + b]) % mod
                    }
        }
    println(ans)
}