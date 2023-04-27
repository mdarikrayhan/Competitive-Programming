/***************************************************//* .  . . . . .  . . . Author : Md. Arik Rayhan  . . .  . . . .  . . *//*  .  . . . . Github : github.com/mdarikrayhan   .  . *//***************************************************/fun main()=repeat(readLine()!!.toInt()){
    val (n, k)=readLine()!!.split(" ").map{ it.toInt() }
    val n1 = n/(1+k+k*k+k*k*k)
    println("$n1 ${n1*k} ${n1*k*k} ${n1*k*k*k}")
}