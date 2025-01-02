import kotlin.math.min
import kotlin.math.max
import java.util.*
import kotlin.system.exitProcess
 
private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()
 
fun main()
{
    var (n,m)=readInts()
    var a=MutableList(n+1,{MutableList(n+1,{false})})
    for(i in 0..m-1)
    {
        var (x,y)=readInts()
        a[x][y]=true
        a[y][x]=true
    }
    var id=MutableList(n+1,{0})
    var idx=1
    for(i in 1..n)
    {
        for(j in 1..i-1)
        {
            if(a[i]==a[j])
            {
                id[i]=id[j]
                break
            }
        }
        if(id[i]==0) id[i]=idx++
    }
    var b=MutableList(idx,{MutableList(idx,{false})})
    for(i in 1..n) for(j in 1..n) if(a[i][j]==true) b[id[i]][id[j]]=true
    var c=MutableList(idx,{-1})
    var used=MutableList(16,{false})
    fun solve(x:Int):Unit
    {
        if(x==idx)
        {
            for(i in 1..n) print("${c[id[i]]} ")
            print("\n")
            exitProcess(0)
        }
        for(i in 0..15)
        {
            if(used[i]==true) continue
            var ok=true
            for(y in 1..x-1)
            {
                var one=b[x][y]
                var tmp=(i xor c[y])
                var two=(tmp==1||tmp==2||tmp==4||tmp==8)
                if(one!=two) ok=false
            }
            if(ok==true)
            {
                c[x]=i
                used[i]=true
                solve(x+1)
                used[i]=false
            }
        }
    }
    solve(1)
}