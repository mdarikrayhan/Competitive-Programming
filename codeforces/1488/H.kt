import kotlin.math.*

const val mod = 998244353;

class Mat {
  val a = Array<Array<Int>>(4) { Array<Int>(4) {0}; };
};

fun mul(x : Mat, y : Mat) : Mat {
  var res = Mat();
  for (i in 0 .. 3) for (j in 0 .. 3) for (k in 0 .. 3) {
    res.a[i][j] = ((res.a[i][j].toLong() + 1L * x.a[i][k] * y.a[k][j] % mod) % mod).toInt();
  }
  return res;
}

fun main() {
  var (n, q) = readln().split(' ').map { it.toInt(); };
  var a = readln().split(' ').map { it.toInt(); }.toTypedArray();
  var t = Array<Mat>(n * 4) { Mat() };

  var sm = Mat();
  var bg = Mat();
  var smd = Mat();
  var bgd = Mat();
  var base = Mat();

  for (i in 0 .. 3) {
    for (j in 0 .. 3) {
      if (i < j) sm.a[i][j] = 1;
      if (i <= j) smd.a[i][j] = 1;
      if (i > j) bg.a[i][j] = 1;
      if (i >= j) bgd.a[i][j] = 1;
    }
  }

  for (i in 0 .. 3) base.a[0][i] = 1;

  fun upd(c : Int, l : Int, r : Int, x : Int, v : Mat) {
    if (l == r) {
      t[c] = v;
      return;
    }
    val mid = (l + r) shr 1;
    if (x <= mid) upd(c + c, l, mid, x, v);
    else upd(c + c + 1, mid + 1, r, x, v);
    t[c] = mul(t[c + c], t[c + c + 1]);
  }

  fun solve(x : Int) {
    if (x == n - 1) {
      if (a[x - 1] == 0) {
        upd(1, 1, n - 1, n - 1, bgd);
      } else {
        upd(1, 1, n - 1, n - 1, sm);
      }
    } else {
      if (a[x - 1] == 0 && a[x] == 0) {
        upd(1, 1, n - 1, x, bgd);
      } else if (a[x - 1] == 0 && a[x] == 1) {
        upd(1, 1, n - 1, x, bg);
      } else if (a[x - 1] == 1 && a[x] == 0) {
        upd(1, 1, n - 1, x, sm);
      } else if (a[x - 1] == 1 && a[x] == 1) {
        upd(1, 1, n - 1, x, smd);
      }
    }
  }

  for (i in 1 .. n - 1) solve(i);

  val o = ArrayList<Int>();

  while (q-- > 0) {
    val x = readln().toInt();
    a[x - 1] = a[x - 1] xor 1;
    if (x - 1 > 0) solve(x - 1);
    solve(x);
    val ans = mul(base, t[1]);
    var sum = 0;
    for (i in 0 .. 3) sum = (sum + ans.a[0][i]) % mod;
    o.add(sum);
  }
  println(o.joinToString("\n"));
}