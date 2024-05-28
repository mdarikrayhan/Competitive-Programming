fun main() {
  val N = 500043
  val n = readLine()!!.toInt()
  val pts = Array(N) { ArrayList<Int>() }
  repeat(n) {
    val (x, y) = readLine()!!.split(" ").map { it.toInt() }
    pts[y].add(x)
  }
  pts.forEach { it.sort() }
  
  data class Event(val y : Int, val t : Int, val value : Int)
  
  fun recalc(v1 : ArrayList<Pair<Int, Int>>, v2 : ArrayList<Int>, flag : Boolean) : ArrayList<Pair<Int, Int>> {
    val events = ArrayList<Event>()
    if (flag) {
      v1.forEach { events.add(Event(it.first, 0, it.second)) }
      v2.forEachIndexed { i, value -> events.add(Event(value, 1, i + 1)) }
      events.add(Event(0, 1, 0))
      events.sortWith(compareBy({ -it.y }, { it.t }, { it.value }))
    } else {
      v1.forEach { events.add(Event(it.first, 0, it.second)) }
      v2.forEachIndexed { i, value -> events.add(Event(value, 1, v2.size - i)) }
      events.add(Event(N + 43, 1, 0))
      events.sortWith(compareBy({ it.y }, { it.t }, { it.value }))
    }
    var cur = 0
    val res = ArrayList<Pair<Int, Int>>()
    events.forEach { 
      if (it.t == 0) {
        cur = maxOf(cur, it.value)
      } else {
        res.add(Pair(it.y, it.value + cur))
      }
    }
    return res
  }
  
  fun calc(flag : Int) : Int {
    var cur = ArrayList<Pair<Int, Int>>()
    pts.forEachIndexed { i, value -> cur = recalc(cur, value, flag != i % 2) }
    var res = 0
    cur.forEach { res = maxOf(res, it.second) }
    return res
  }
  
  println(calc(0) + calc(1) - n)
}