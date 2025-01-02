import java.util.Queue
import java.util.LinkedList

fun main() {
  val (n1, n2, m) = readLine()!!.split(" ").map { it.toInt() }
  val S = n1 + n2
  val T = S + 1
  val V = T + 1
  
  data class Edge(val y : Int, val c : Int, var f : Int, val cost : Int)
  
  val e = ArrayList<Edge>()
  val g = Array(V) { ArrayList<Int>() }
  
  fun addEdge(x : Int, y : Int, c : Int, cost : Int) {
    g[x].add(e.size)
    e.add(Edge(y, c, 0, cost))
    g[y].add(e.size)
    e.add(Edge(x, 0, 0, -cost))
  }
  
  var sum = 0
  readLine()!!.split(" ").mapIndexed { i, value ->
    val k = value.toInt()
    addEdge(i, T, 1, -k)
    sum += k
  }
  
  val deg = IntArray(n2) { 0 }
  repeat(m) {
    val (x, y) = readLine()!!.split(" ").map { it.toInt() - 1 }
    addEdge(y + n1, x, 1, 0)
    deg[y] += 1
  }
  
  for (i in 0 until n2) {
    addEdge(S, i + n1, deg[i] - 1, 0)
  }
  
  var mincost = 0
  
  fun enlarge() : Boolean {
    val q: Queue<Int> = LinkedList<Int>()
    val inq = IntArray(V) { 0 }
    val d = IntArray(V) { 1e9.toInt() }
    val p = IntArray(V) { -1 }
    val pe = IntArray(V) { -1 }
    
    q.add(S)
    inq[S] = 1
    d[S] = 0

    while (!q.isEmpty()) {
      val k = q.poll()
      g[k].forEach { a ->
        val (to, c, f, w) = e[a]
        if (c - f != 0 && d[to] > d[k] + w) {
          d[to] = d[k] + w
          p[to] = k
          pe[to] = a
          if (inq[to] == 0) {
            q.add(to)
            inq[to] = 1
          }
        }
      }
    }
    
    if (p[T] == -1) return false
    
    var cur = T
    while (cur != S) {
      mincost += e[pe[cur]].cost
      e[pe[cur]].f += 1
      e[pe[cur] xor 1].f -= 1
      cur = p[cur]
    }
    
    return true
  }
  
  while (enlarge());
  
  println(sum + mincost)
  
}