import java.lang.Math.log
import java.util.*
import javax.net.ssl.TrustManagerFactorySpi
import kotlin.math.*

private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readLong() = readStr().toLong() // single long int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long ints

tailrec fun gcd(x:Int,y:Int):Int{
    if(x==0 || y==0)return max(x,y)
    return gcd(y,x%y)
}
fun solve(){
    val (k,n)=readInts()
    val p=readInts().toSortedSet()
    val x=readInts()
    if(n==2){
        println("YES")
        println("${x[0]} ${p.first()}")
        println("${x[1]} ${p.first()}")
        return
    }
    var y=MutableList(1000001){0}
    for(i in p){
        for(j in 1..1000000/i){
            y[i*j]=i
        }
    }
    for(leave in 0..2){
        var (i,j)=mutableListOf(0,1,2)-leave
        val diff=x[j]-x[i]
        for(div in 1..diff){
            if(diff%div==0 && p.contains(div)){
                //check this div
                var g=0
                var lst1=x[i]
                var lst2=-1
                for(num in x){
                    if(abs(num-lst1)%div==0){
                        lst1=min(lst1,num)
                    }else{
                        if(lst2==-1)lst2=num
                        else{
                            g=gcd(g,abs(num-lst2))
                            lst2=min(lst2,num)
                        }

                    }
                }
                if(g==0)g=p.first()
                if(lst2==-1)lst2=x[i]
                if(y[g]!=0){
                    println("YES")
                    println("${lst1} $div")
                    println("${lst2} ${y[g]}")
                    return
                }
            }
        }
    }
    println("NO")
}
fun main(){
//    val t = readInt();
    val t = 1


    for (i in 1..t){
        solve()
    }
}