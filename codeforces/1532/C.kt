fun main(){
    repeat(readLine()!!.toInt()){
        val (n, k) = readLine()!!.split(" ").map {it.toInt()}
        println(CharArray(n) {'a' + (it % k)})
    }
}