fun main() {
  val AL = 5
  val (n, m) = readLine()!!.split(" ").map { it.toInt() }
  val s = Array(n) { readLine()!! }
  val res = LongArray(1 shl AL) { mask ->
    val d = IntArray(m) { 0 }
    var sum = 0L
    for (i in 0 until n) {
      for (j in 0 until m) {
        val cur = (mask shr (s[i][j] - 'A')) and 1 
        d[j] = if (cur == 1) d[j] + 1 else 0
      }
      val l = IntArray(m) { -1 }
      val q = IntArray(m) { 0 }
      var ptr = -1
      for (j in 0 until m) {
        while (ptr >= 0 && d[q[ptr]] >= d[j]) ptr -= 1
        if (ptr >= 0) l[j] = q[ptr]
        ptr += 1
        q[ptr] = j
      }
      val r = IntArray(m) { m }
      ptr = -1
      for (j in m - 1 downTo 0) {
        while (ptr >= 0 && d[q[ptr]] > d[j]) ptr -= 1
        if (ptr >= 0) r[j] = q[ptr]
        ptr += 1
        q[ptr] = j
      }
      for (j in 0 until m) sum += (j - l[j]) * (r[j] - j) * d[j].toLong()
    }
    sum
  }
  
  for (i in 0 until AL) {
    for (mask in 1 until (1 shl AL)) {
      if (((mask shr i) and 1) == 0) res[mask or (1 shl i)] -= res[mask]
    }
  }
  
  val ans = LongArray(AL + 1) { 0 }
  for (mask in 1 until (1 shl AL)) ans[mask.countOneBits()] += res[mask]
  
  println(ans.drop(1).joinToString(" "))
}