import java.lang.Integer.max

fun modify(x: Int, y: Int, n: Int, f: MutableList<Int>) {
  var p = x
  while (p < n) {
    f[p] = max(f[p], y)
    p = p or (p + 1)
  }
}

fun get(x: Int, f: List<Int>): Int {
  var p = x
  var ret = 0
  while (p >= 0) {
    ret = max(ret, f[p])
    p = (p and (p + 1)) - 1
  }
  return ret
}

fun main() {
  var tt = readLine()!!.toInt()
  while (tt > 0) {
    --tt
    var n = readLine()!!.toInt()
    var a: List<Int> = readLine()!!.split(' ').map {it.toInt() - 1}
    var fenw: MutableList<Int> = MutableList(n) {0}
    var ans = 1
    var last: MutableList<Int> = MutableList(n) {n}
    for (i in n - 1 downTo 0) {
      if (last[a[i]] < n) {
        var my_ans = get(last[a[i]] - 1, fenw) + 2
        if (my_ans > ans) {
          ans = my_ans
        }
        modify(last[a[i]], my_ans, n, fenw)
      }
      modify(i, 1, n, fenw)
      last[a[i]] = i
    }
    println(ans)
  }
}