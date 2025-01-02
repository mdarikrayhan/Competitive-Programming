fun main() = repeat(readLine()!!.toInt()) {
  val (n, m) = readLine()!!.split(" ").map { it.toInt() }
  val a = Array(n) { readLine()!!.split(" ").map { it.toInt() } }
  val used = BooleanArray(111) { false }
  val ord = ArrayList<Int>()
  
  val dx = intArrayOf(0, 1, 0, -1)
  val dy = intArrayOf(1, 0, -1, 0)
  
  fun dfs(x : Int, y : Int) {
    ord.add(a[x][y])
    used[a[x][y]] = true
    for (i in 0 until 4) {
      val nx = x + dx[i]
      val ny = y + dy[i]
      if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != 0 && !used[a[nx][ny]]) {
        dfs(nx, ny)
        ord.add(a[x][y])
      }
    }
  }
  
  var k = 0
  
  for (x in 0 until n) {
    for (y in 0 until m) {
      if (a[x][y] != 0) {
        k += 1
        if (ord.isEmpty()) dfs(x, y)
      }
    } 
  }
  
  if (ord.count() != 2 * k - 1) {
    return@repeat println(-1)
  }
  
  println("$k $k")
  for (x in 0 until k) {
    for (y in 0 until k) {
      print("${ord[x + y]} ")
    }
    println()
  }
}