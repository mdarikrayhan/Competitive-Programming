fun main() = repeat(readLine()!!.toInt()) {
    val p = readLine()!!.split(" ").map{it.toLong()}
    println(p[0]*(p[2]/2+p[2]%2)-p[1]*(p[2]/2)) }