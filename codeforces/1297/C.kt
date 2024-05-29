fun solve() {
    val N = readLine()!!.toInt()
    val A = readLine()!!.split(" ").map { it.toInt() }
    val S = IntArray(N)
    var ans = 0
    for (i in 0 until N) {
        if (A[i] > 0) {
            ans += A[i]
            S[i] = 1
        }
    }

    var mi = 1000000
    var miIdx = -1
    for (i in 0 until N) {
        if (A[i] != 0 && mi > Math.abs(A[i])) {
            mi = Math.abs(A[i])
            miIdx = i
        }
    }

    S[miIdx] = S[miIdx].xor(1)
    println(ans - mi)
    println(S.joinToString(""))
}

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        solve()
    }
}
