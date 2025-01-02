fun main(){
    repeat(readLine()!!.toInt()){
        val n=readLine()!!.toInt()
        var l=0
        var r=2e5.toInt()
        for(i in 1..n) {
            val pairs=readLine()!!.split(' ')
            val limit=pairs[0].commonSuffixWith(pairs[1]).length
            if(pairs[2]=="0")
                l=maxOf(l,limit+1)
            else
                r=minOf(r,limit)
        }
        println(maxOf(0,r-l+1))
        if(r-l+1>0)
           println((l..r).joinToString(" "))
    }
}