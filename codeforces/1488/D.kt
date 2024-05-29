fun main() {
  val t = readLine()!!.toInt()
  for (i in 0 until t) {
    var (n, s) = readLine()!!.split(" ").map(String::toLong)
    if (n == 1L) {
      println(s)
      continue
    }
    if (n > 60) {
      s -= n - 60
      n = 60
    }
    var base = 1L
    for (j in 0 until n) {
      val coeff = (1L.shl((n - j).toInt())) - 1
      base = base.coerceAtLeast((s - 1) / coeff + 1)
      s -= base
    }
    println(base)
  }
}
