fun main() {
    readLine()
    val students = readLine()!!.split(' ').map{it.toInt()}.sorted()
    println(students.chunked(2).sumOf { it[1] - it[0]})
}



