private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var m = readInt()
    var from = IntArray(m)
    var to = IntArray(m)
    for (i in 0..m-1) {
        var s = readLn()
        from[i] = 0
        if (s[0] == 'o') from[i] = 1
        if (s[0] == 't') from[i] = 2
        if (s[0] == 'l') from[i] = 3
        if (s[0] == 'i') from[i] = 4
        if (s[0] == 'n') from[i] = 5
        to[i] = (from[i] + s.length) % 6
    }
    var n = 6
    val g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
    for (i in 0 until m) {
        g[from[i]].add(i)
    }
    val used = BooleanArray(m)
    val ptr = IntArray(n)
    val res = IntArray(m)
    var write_ptr = m
    var stack_ptr = 0
    for (root in 0 until n) {
        var v = root
        while (true) {
            var found = false
            while (ptr[v] < g[v].size) {
                var id = g[v][ptr[v]++]
                if (used[id]) {
                    continue
                }
                used[id] = true
                res[stack_ptr++] = id
                v = v xor from[id] xor to[id]
                found = true
                break
            }
            if (!found) {
                if (stack_ptr == 0) {
                    break;
                }
                var id = res[--stack_ptr]
                res[--write_ptr] = id
                v = v xor from[id] xor to[id]
            }
        }
    }
    for (i in 0..m-1) res[i]++
    println(res.joinToString(" "))
}