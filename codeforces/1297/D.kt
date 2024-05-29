fun solve() {
    val (N, K) = readLine()!!.split(" ").map { it.toInt() }
    var remainingK = K.toLong()
    val A = readLine()!!.split(" ").map { it.toLong() }.toMutableList()
    val B = A.toList()

    val dat = mutableListOf<Pair<Long, Int>>()
    for (i in 0 until N) {
        dat.add(A[i] to i)
    }
    dat.sortBy { it.first }
    val idx = IntArray(N)
    for (i in 0 until N) {
        A[i] = dat[i].first
        idx[i] = dat[i].second
    }

    for (i in 0 until N) {
        A[i] -= i.toLong()
    }

    fun check(x: Long): Boolean {
        var cost = 0L
        for (i in 0 until N) {
            cost += maxOf(0L, x - A[i])
        }
        return cost <= remainingK
    }

    var (ok, ng) = 0L to (1L shl 40)
    while (ok + 1 < ng) {
        val x = (ok + ng) / 2
        if (check(x)) {
            ok = x
        } else {
            ng = x
        }
    }

    val x = ok

    for (i in 0 until N) {
        val add = maxOf(x - A[i], 0)
        A.set(i, A[i] + add)
        remainingK -= add
    }


    for (i in 0 until N) {
        if (i == N - 1 || A[i] < A[i + 1]) {
            var p = i
            while (remainingK > 0 && p >= 0) {
                A.set(p, A[p] + 1)
                remainingK--
                p--
            }
        }
    }

    val ANS = LongArray(N)
    for (i in 0 until N) {
        A.set(i, A[i] + i)
        ANS[idx[i]] = A[i] - B[idx[i]]
    }
    println(ANS.joinToString(" "))
}

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        solve()
    }
}
