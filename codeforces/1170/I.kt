import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

/**
 * @author: pashka
 */

val MOD = 998244353L

internal class SegmentTree(private val size: Int) {

    private val sum = LongArray(4 * size)
    private val add = LongArray(4 * size)
    private val mult = LongArray(4 * size)

    public fun add(l: Int, r: Int, c: Long) {
        add(0, 0, size, l, r, c)
    }

    private fun add(n: Int, ll: Int, rr: Int, l: Int, r: Int, c: Long) {
        push(n, ll, rr)
        if (ll >= l && rr <= r) {
            add[n] += c
            sum[n] += c * (rr - ll)
            add[n] %= MOD
            sum[n] %= MOD
        } else if (ll >= r || l >= rr) {
            return
        } else {
            val m = (ll + rr) / 2
            add(n * 2 + 1, ll, m, l, r, c)
            add(n * 2 + 2, m, rr, l, r, c)
            sum[n] = (sum[2 * n + 1] + sum[2 * n + 2]) % MOD
        }
    }

    public fun mult(l: Int, r: Int, c: Long) {
        mult(0, 0, size, l, r, c)
    }

    private fun mult(n: Int, ll: Int, rr: Int, l: Int, r: Int, c: Long) {
        push(n, ll, rr)
        if (ll >= l && rr <= r) {
            mult[n] *= c
            add[n] *= c
            sum[n] *= c
            mult[n] %= MOD
            add[n] %= MOD
            sum[n] %= MOD
        } else if (ll >= r || l >= rr) {
            return
        } else {
            val m = (ll + rr) / 2
            mult(n * 2 + 1, ll, m, l, r, c)
            mult(n * 2 + 2, m, rr, l, r, c)
            sum[n] = (sum[2 * n + 1] + sum[2 * n + 2]) % MOD
        }
    }

    private fun push(n: Int, ll: Int, rr: Int) {
        if (rr - ll > 1) {
            val m = ll + rr shr 1
            for (i in 1..2) {
                mult[2 * n + i] *= mult[n]
                add[2 * n + i] *= mult[n]
                sum[2 * n + i] *= mult[n]
                add[2 * n + i] += add[n]
                sum[2 * n + i] += add[n] * (if (i == 1) (m - ll) else (rr - m))
                mult[2 * n + i] %= MOD
                add[2 * n + i] %= MOD
                sum[2 * n + i] %= MOD
            }
        }
        add[n] = 0
        mult[n] = 1
    }

    public fun sum(l: Int, r: Int): Long {
        return sum(0, 0, size, l, r)
    }

    private fun sum(n: Int, ll: Int, rr: Int, l: Int, r: Int): Long {
        push(n, ll, rr)
        if (ll >= l && rr <= r) {
            return sum[n]
        } else if (ll >= r || l >= rr) {
            return 0
        } else {
            val m = (ll + rr) / 2
            return (sum(n * 2 + 1, ll, m, l, r) + sum(n * 2 + 2, m, rr, l, r)) % MOD
        }
    }
}

private fun solve() {
    val n = nextInt()
    val l = IntArray(n)
    val r = IntArray(n)
    for (i in 0 until n) {
        l[i] = nextInt()
        r[i] = nextInt()
    }
    var all = l + r
    all.sort()
    var m = 1
    for (i in 1 until all.size) {
        if (all[i] != all[m - 1]) {
            all[m] = all[i]
            m++
        }
    }
    all = all.copyOf(m)
    for (i in 0 until n) {
        l[i] = all.binarySearch(l[i])
        r[i] = all.binarySearch(r[i])
    }
    val c = IntArray(2 * m)
    for (i in 0 until n) {
        c[l[i] * 2]++
        c[r[i] * 2 + 1]--
    }
    for (i in 1 until 2 * m) {
        c[i] += c[i - 1]
    }
    val q = IntArray(2 * m)
    var mm = 0
    for (i in 0 until 2 * m) {
        if (c[i] > 0) {
            q[i] = mm
            mm++
        }
    }
    m = mm
    for (i in 0 until n) {
        l[i] = q[2 * l[i]]
        r[i] = q[2 * r[i]]
    }
    var p = List(n) { x: Int -> x }.sortedBy { x: Int -> r[x] }
    val st = SegmentTree(m + 1)
    st.add(0, 1, 1)
    for (i in p) {
        st.mult(0, l[i], 2)
        val x = st.sum(l[i], r[i] + 2)
        st.add(r[i] + 1, r[i] + 2, x)
    }
    out.println(st.sum(m, m + 1))
}

fun main() {
    solve()
    out.close()
}

private var br = BufferedReader(InputStreamReader(System.`in`))
private var st: StringTokenizer? = null
private var out = PrintWriter(System.out)

@Throws(IOException::class)
private fun next(): String {
    while (st == null || !st!!.hasMoreTokens()) {
        st = StringTokenizer(br.readLine())
    }
    return st!!.nextToken()
}

@Throws(IOException::class)
private fun nextInt(): Int {
    return Integer.parseInt(next())
}