fun main(){
    val n =readLine()!!.toInt()
    var ANS=IntArray(n)

    for (i in 1..n){
        for (j in i+i..n step i){
            ANS[j-1]+=1
        }
        ANS[i-1]-=n/i-1
    }

    //println(ANS.joinToString (" "))

    ANS.sort()

    //println(ANS.joinToString (" "))

    val ANSLIST=IntArray(n)
    var k=0

    for (i in  0..n-1){
        k+=ANS[n-1-i]
        ANSLIST[i]=k

    }

    println(ANSLIST.joinToString (" "))




}