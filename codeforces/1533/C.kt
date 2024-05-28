fun main() = repeat(readLine()!!.toInt()) {
  val (n, k) = readLine()!!.split(" ").map { it.toInt() }
  val s = readLine()!!
  val used = BooleanArray(n) { false }
  var cnt = s.count({ it == '1'})
  var pos = 0
  while (cnt > 0) {
    used[pos] = true
    if (s[pos] == '1') --cnt
    if (cnt == 0) break
    var lft = k
    while (lft > 0) {
      pos = (pos + 1) % n
      if (!used[pos]) --lft;
    }
  }
  println(used.count({ it }))
}