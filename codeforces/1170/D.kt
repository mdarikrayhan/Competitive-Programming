fun main() {
    readln()
    val a = readln().split(" ").map { it.toInt() }
    val m = a.count { it == -1 }
    val lists = Array(m) { ArrayList<Int>() }
    val indices = ArrayDeque(lists.indices.toList())
    for (x in a) {
        val i = indices.removeFirst()
        if (x == -1) continue
        lists[i].add(x)
        indices.add(i)
    }

    println(m)
    println(lists.joinToString("\n") {
        "${it.size} ${it.joinToString(" ")}"
    })
}
