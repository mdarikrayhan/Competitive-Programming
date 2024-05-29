fun main() {
  val tests = readLine()!!.toInt()
  repeat(tests) {
    val vertices = readLine()!!.toInt()
    val tree = Array(vertices) { arrayListOf<Pair<Int, Int>>() }
    repeat(vertices - 1) {
      val (v, u) = readLine()!!.split(' ').map { it.toInt() - 1 }
      tree[v].add(u to it)
      tree[u].add(v to it)
    }
    val answer = IntArray(vertices - 1)
    val dp = IntArray(vertices)
     fun paint(limit: Int): Boolean {
      answer.fill(-1)
      dp.fill(0)
      var nextColor = 1
       fun paint(vertex: Int, parent: Int, color: Int) {
        for ((child, index) in tree[vertex]) if (child != parent) {
          if (answer[index] == -1) {
            answer[index] = color
            paint(child, vertex, color)
          }
        }
      }
       fun dfs(vertex: Int, parent: Int = -1): Boolean {
        val knapsack = IntArray(limit + 1) { -1 }
        knapsack[0] = 0
        var total = 0
        for ((index, edge) in tree[vertex].withIndex()) if (edge.first != parent) {
          val child = edge.first
          if (!dfs(child, vertex)) {
            return false
          }
          total += dp[child] + 1
          for (w in limit - (dp[child] + 1) downTo 0) {
            if (knapsack[w] >= 0 && knapsack[w + dp[child] + 1] < 0) {
              knapsack[w + dp[child] + 1] = index
            }
          }
        }
        for (w in limit downTo 0) {
          if (knapsack[w] >= 0) {
            var cur = w
            while (cur > 0) {
              val (child, index) = tree[vertex][knapsack[cur]]
              answer[index] = nextColor
              paint(child, vertex, nextColor)
              cur -= dp[child] + 1
            }
            dp[vertex] = total - w
            if (w > 0) nextColor++
            break
          }
        }
        return dp[vertex] <= limit
      }
       if (dfs(0)) {
        paint(0, -1, nextColor)
        return true
      }
      return false
    }
     var left = 0
    var right = vertices
    while (right - left > 1) {
      val test = (right + left) ushr 1
      if (paint(test)) {
        right = test
      } else {
        left = test
      }
    }
     assert(paint(right))
    println(right)
    println(answer.joinToString(" "))
  }
}