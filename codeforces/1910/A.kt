fun main() {
    repeat(readInt()) {
        println(readln().dropLastWhile { it == '0' }.dropLast(1))
    }
}

private fun readInt() = readln().toInt()