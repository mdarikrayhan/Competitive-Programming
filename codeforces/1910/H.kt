private fun digitSum(a: Int) = a.toString().toCharArray().sumOf { it.digitToInt() }
private fun List<Int>.lowerBound(x: Int) = binarySearch { if (it < x) -1 else 1 }.inv()
fun main() {
    val n = readInt()
    val a = readInts()
    val pw10 = buildList<Int> {
        add(1)
        repeat(9) { add(last() * 10) }
        removeAt(0)
    }
    val d = pw10.map { p -> a.map { it % p }.sorted() }
    val ds = a.sumOf { digitSum(it) }
    println(a.map { x ->
        ds + n * digitSum(x) - 9 * pw10.indices.sumOf {
            n - d[it].lowerBound(pw10[it] - (x % pw10[it]))
        }
    }.joinToString(" "))
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }