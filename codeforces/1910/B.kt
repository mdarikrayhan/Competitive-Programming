fun main() = repeat(readLine()!!.toInt()) {
  val s = readLine()!!.toCharArray()
  val x = s.indexOf('-').takeIf { it >= 0 } ?: 0
  val y = s.lastIndexOf('+').takeIf { it >= x } ?: x
  s[x] = s[y].also { s[y] = s[x] }
  val bal = s.runningFold(0) { cur, c -> cur + if (c == '-') -1 else 1 }
  println(if (bal.min() == 0) "${x + 1} ${y + 1}" else "-1")
}