import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private class obj
(
    var a_plus:Long=0L,
    var a_minus:Long=0L,
    var b_plus:Long=0L,
    var b_minus:Long=0L,
    var best:Long=0L
)
{
    constructor(one:obj,two:obj):this() {pull(one,two)}
    fun ini(a:Long,b:Long,s:Long)
    {
        a_plus=a+s
        a_minus=a-s
        b_plus=b+s
        b_minus=b-s
        best=a+b
    }
    fun pull(l:obj,r:obj)
    {
        best=minOf(l.best,r.best,l.a_minus+r.b_plus,l.b_minus+r.a_plus)
        a_plus=minOf(l.a_plus,r.a_plus)
        a_minus=minOf(l.a_minus,r.a_minus)
        b_plus=minOf(l.b_plus,r.b_plus)
        b_minus=minOf(l.b_minus,r.b_minus)
    }
}

private val N=300005
private var tree=MutableList(4*N,{obj()})
private var a=mutableListOf<Long>()
private var b=mutableListOf<Long>()
private var s=MutableList(N,{0L})
private val inf=(1L shl 60)

private fun build(idx:Int,l:Int,r:Int)
{
    if(l==r) tree[idx].ini(a[l],b[l],s[l])
    else
    {
        var m=(l+r)/2
        build(2*idx,l,m)
        build(2*idx+1,m+1,r)
        tree[idx].pull(tree[2*idx],tree[2*idx+1])
    }
}

private fun query(idx:Int,l:Int,r:Int,ql:Int,qr:Int):obj
{
    if(ql>qr) return obj(inf,inf,inf,inf,inf)
    if(l==ql&&r==qr) return tree[idx]
    var m=(l+r)/2
    return obj(query(2*idx,l,m,ql,minOf(qr,m)),query(2*idx+1,m+1,r,maxOf(ql,m+1),qr))
}

fun main()
{
    var n=readInt()
    a=(mutableListOf(0L)+readLongs()).toMutableList()
    b=(mutableListOf(0L)+readLongs()).toMutableList()
    var c=(mutableListOf(0L)+readLongs()).toMutableList()
    for(i in 1..n) s[i]=s[i-1]+c[i]
    var q=readInt()
    build(1,1,n-1)
    while((q--)>0)
    {
        var (l,r)=readInts()
        var t=query(1,1,n-1,l,r-1)
        var res=minOf(t.best,t.a_plus-s[l-1],t.a_minus+s[r])
        print("${res} ")
    }
    print("\n")
}