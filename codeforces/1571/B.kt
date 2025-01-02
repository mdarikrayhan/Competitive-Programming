fun main(args: Array<String>) = repeat(readLine()!!.toInt()) {
	val n = readLine()!!.toInt()
	val (a,va) = readLine()!!.split(" ").map{it.toInt()}
	val (c,vc) = readLine()!!.split(" ").map{it.toInt()}
	val b = readLine()!!.toInt()
	println(Math.min(vc,va+(b-a))) }