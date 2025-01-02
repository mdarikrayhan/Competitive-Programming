fun main() {
    repeat(readLine()!!.toInt()) { println(readLine()!!.split(' ').sumOf {it.toInt()}) }
}