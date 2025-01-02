fun main(args: Array<String>){
    val n = readLine()!!.toInt()
	val a = readLine()!!.split(" ").map{ it.toLong() }
	val b = a.sorted()
	val s = a.sum()
	var ans: MutableList<Int> = mutableListOf()
	for (i in 0..n-1) {
	    if ((s - a[i]) == (if (a[i]==b[n-1]) {b[n-2]} else {b[n-1]}) * 2) {
	        ans.add(i+1)
	    }
	}
	println("${ans.size}")
	println(ans.joinToString(separator=" "))
}