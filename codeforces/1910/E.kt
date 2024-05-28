fun main() = repeat(readLine()!!.toInt()) {
  val n = readLine()!!.toInt()
  val a = readLine()!!.split(" ").map { it.toLong() }
  val b = readLine()!!.split(" ").map { it.toLong() }
  val dp = Array(3) { LongArray(3) { 0 } }
  for ((x, y) in a zip b) {
    for (i in 0..2) for (j in 0..2) {
      dp[i][j] += maxOf(
      	(if (i == 1) x else 0) + (if (j == 1) y else 0),
      	(if (i == 1) y else 0) + (if (j == 1) x else 0)
      );
    }
    for (i in 0..2) for (j in 0..2) {
      if (i < 2) dp[i + 1][j] = maxOf(dp[i + 1][j], dp[i][j]);
      if (j < 2) dp[i][j + 1] = maxOf(dp[i][j + 1], dp[i][j]);
    }
  }
  println(dp[2][2]);
}