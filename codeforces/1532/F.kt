fun main() {
    val n = readLine()!!.toInt()
    val listPS = List(n * 2 - 2) { readLine()!! }
    val maxPS = listPS.filter { it.length == n - 1 }
    var prefixes = List(n - 1) { maxPS[0].take(it + 1) }.toMutableSet()
    val intersect = listPS.toSet() intersect prefixes
    val ps = if (intersect.size == n - 1 && maxPS[0].drop(1) == maxPS[1].dropLast(1))
        'P' to 'S'
    else {
        prefixes = List(n - 1) { maxPS[0].drop(it) }.toMutableSet()
        'S' to 'P'
    }
    for (s in listPS) if (s in prefixes) {
        prefixes.minusAssign(s)
        print(ps.first)
    } else
        print(ps.second)
}