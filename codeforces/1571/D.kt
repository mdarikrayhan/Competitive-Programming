fun main(){

    val (n, m) = readLine()!!.split(" ").map{it.toInt()}
    val (W, L) = readLine()!!.split(" ").map{it.toInt() - 1}

    val w = IntArray(n)
    val l = IntArray(n)

    val wl = Array(n){IntArray(n)}

    for(i in 1 until m){
        val (a, b) = readLine()!!.split(" ").map{it.toInt() - 1}
        w[a]++
        l[b]++
        wl[a][b]++
    }

    var ans = 0
    for(i in 0 until n){
        if(i == W)continue
        for(j in 0 until n){
            if(j == L)continue
            if(i == j)continue
            val now = w[i] + l[j] - wl[i][j]
            ans = ans.coerceAtLeast(now)
        }
    }
    println(ans + 1)

}