import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

/**
 * @author: pashka
 */

fun solve(a: IntArray): IntArray {
    val n = a.size
    var l = 0
    var r = a.size + 1
    var best = IntArray(0)
    while (r > l + 1) {
        var m = (l + r) / 2
        val c = IntArray(m)
        for (i in 0 until m) {
            if (i % 2 == 0) {
                c[i] = a[i / 2]
            } else {
                c[i] = a[n - m / 2 + i / 2]
            }
        }
        var ok = true
        for (i in 0 until m - 1) {
            if (c[i] == c[i + 1]) {
                ok = false
            }
        }
        if (!ok && m % 2 == 0) {
            for (i in 0 until m step 2) {
                val t = c[i]
                c[i] = c[i + 1]
                c[i + 1] = t
            }
            ok = true
            for (i in 0 until m - 1) {
                if (c[i] == c[i + 1]) {
                    ok = false
                }
            }
        }
        if (ok) {
            l = m
            best = c
        } else {
            r = m
        }
    }
    return best
}

private fun solveTest() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    a.sort()
    val best1 = solve(a)
    a.reverse()
    val best2 = solve(a)
    val best = if (best1.size > best2.size) best1 else best2
    println(best.size)
    println(best.joinToString(" "))
}

fun main() {
    val n = readLine()!!.toInt()
    for (i in 0 until n) {
        solveTest()
    }
}