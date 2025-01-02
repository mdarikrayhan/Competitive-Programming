import java.util.*

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve() {
    val (n,m,k) = nextInts()
    var A = nextLongs()
    var a = arrayListOf<Long>()
    a.addAll(A)
    a.sort()
    var ans = (1e18).toLong()
    var ind = 0
    var above:Long = 0
    var below:Long = 0
    for (i in 0..m-1) above += a[i]-a[0]
    for (i in 0..n-m) {
        val des = i+(m-1)/2
        while (ind < des) { // try to get closer to median if possible
            if (below+(a[ind+1]-a[ind])*(ind+1-i) <= k) {
                below += (a[ind+1]-a[ind])*(ind+1-i)
                above -= (a[ind+1]-a[ind])*(i+m-1-ind) // ind+1 to i+m-1
                ind ++
            } else break
        }
        assert (k >= below)
        if (ind < des) {
            var oops: Long = (k-below)/(ind+1-i)
            ans = minOf(ans,below+above-(i+m-1-ind)*oops+(ind+1-i)*oops)
            assert(i+m-1-ind >= ind+1-i)
        } else ans = minOf(ans,above+below)
        if (i < n-m) {
            below -= a[ind]-a[i]
            above += a[i+m]-a[ind]
        }
    }
    print(ans)
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) solve()
}