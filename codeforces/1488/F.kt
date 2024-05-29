fun main() {
 readLn()
 val c = readInts()
 val queriesCount = readInt()
 val queries = List(queriesCount) {
  val (l, r) = readInts()
  l - 1 to r
 }.withIndex().groupBy { it.value.second }
 val ans = LongArray(queriesCount) { 0 }
 val xs = mutableListOf<Int>()
 val ys = mutableListOf<Int>()
 val areas = mutableListOf<Long>()
 fun value(x: Int): Long {
  val i = xs.binarySearch(x - 1).let { if (it >= 0) it else -1 - it }
  return areas[i] - ys[i].toLong() * (xs[i] - x + 1)
 }
 for (i in c.indices) {
  while (ys.isNotEmpty() && ys.last() <= c[i]) {
   xs.removeLast()
   ys.removeLast()
   areas.removeLast()
  }
  val xPrev = xs.lastOrNull() ?: -1
  xs.add(i)
  ys.add(c[i])
  val areaPrev = areas.lastOrNull() ?: 0
  areas.add((i - xPrev) * c[i].toLong() + areaPrev)
  for (query in queries[i + 1].orEmpty()) {
   ans[query.index] = value(i + 1) - value(query.value.first)
  }
 }
 println(ans.joinToString(" "))
}
 private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }