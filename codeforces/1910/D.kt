private fun solve() : Boolean {
    val n = readInt()
    val a = readInts().toIntArray()
    var dropped = false
    for (i in 1 until n) {
        if (a[i] == a[i-1]) {
            a[i]++
        } else if (a[i] < a[i-1]) {
            if (dropped) return false
            dropped = true
            if (i != 1) {
                when {
                    a[i-2] > a[i] -> a[i] = a[i-1]
                    a[i-2] == a[i] -> a[i]++
                    else -> {}
                }
            }
        }
    }
    return true
}
fun main() {
    repeat(readInt()) {
        println(if (solve()) "YES" else "NO")
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }