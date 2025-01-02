fun main() {
  val (n, m) = readLine()!!.split(" ").map { it.toInt() }
  val used = Array(n) { readLine()!! }.toSet()
  repeat(readLine()!!.toInt()) {
    val t = readLine()!!
    val s = (0..m).map { i -> t.removeRange(i..i) }.toSet()
    println(s.count { used.contains(it) } )
  }
}