fun main() {
  val s = readLine()!!.map { (it - '0').toInt() }.toIntArray()
  val pos = Array(2) { c -> s.indices.filter { s[it] == c }.toIntArray() }
  val sum = Array(2) { c -> s.runningFold(0) { cur, x -> cur + if (x == c) 1 else 0 }.toIntArray() }
  println((1..s.size).map { k -> 
    generateSequence(0) { i ->
      IntArray(2) { c -> pos[c].getOrElse(sum[c][i] + k) { s.size } }.maxOrNull()!!
    }.indexOf(s.size)
  }.joinToString(" "))
}