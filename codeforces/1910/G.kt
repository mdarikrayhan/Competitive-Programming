fun main() {
    repeat(readln().toInt()) {
        val n = readln().toInt()
        val t = readln().split(' ').map { it.toLong() }

        fun Long.genMoments() = List(n) { (it + 1) * this }

        val sPeriod = t[0]
        val lPeriod = t.firstOrNull { it % sPeriod != 0L }

        val sMoments = sPeriod.genMoments()
        val lMoments = lPeriod?.genMoments() ?: listOf()

        val req = sMoments.union(lMoments).sorted().take(n)
        println(if (req == t) "VALID" else "INVALID")
    }
}