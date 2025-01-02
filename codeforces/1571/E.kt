private fun solve(): Int {
 val n = readInt()
 val s = readLn().map { "()".indexOf(it) }
 val a = readLn()
 val must = IntArray(n) { -1 }
 val diff = BooleanArray(n)
 for (i in a.indices) {
  if (a[i] == '0') continue
  if (must[i] == 1) return -1
  must[i] = 0
  must[i + 3] = 1
  diff[i + 2] = true
 }
 val inf = n + 1
 val ans = s.indices.fold(listOf(0, 0)) { prev, i -> List(2) { j ->
  if (must[i] == 1 - j) inf else
  (if (diff[i]) prev[1 - j] else prev.minOrNull()!!) + (s[i] xor j)
 }}.minOrNull()!!
 return if (ans >= inf) -1 else ans
}
 fun main() = repeat(readInt()) { println(solve()) }
 private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()