fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }
 const val MOD = 998244353
const val PRIMROOT = 3
const val LG = 13
 fun make(cnt: Int,cost: Int): IntArray {
    val ret = IntArray(1 shl LG)
    for(i in 0..cnt) ret[i*cost] = 1
    return ret
}
  var g: Int = 1
var w = IntArray(1 shl LG)
 fun pw(xx: Int, nn: Int): Int {
    var x = xx
    var n = nn
    var ret = 1
    while(true) {
        if((n and 1)!=0) ret=(ret.toLong()*x%MOD).toInt()
        n = n shr 1
        if(n==0) return ret
        x = (x.toLong()*x%MOD).toInt()
    }
}
 fun initfft() {
    g = pw(PRIMROOT,(MOD-1)/(1 shl LG))
    w[0] = 1
    for(i in 1..w.lastIndex) w[i]=(w[i-1].toLong()*g%MOD).toInt()
}
 fun bitrev(a: IntArray) {
    var i = 1
    var j = (1 shl LG) shr 1
    var k = 0
    var l = j
    while(i < (1 shl LG)) {
        if(i < j) a[i] = a[j].also { a[j] = a[i] }
        k = l
        while((k and j)!=0) {
            j = j xor k
            k = k shr 1
        }
        j = j xor k
        ++i
    }
}
 fun dft(a: IntArray) {
    bitrev(a)
    var hlen = 1
    var step = (1 shl LG) shr 1
    while(hlen < (1 shl LG)) {
        var i = 0
        while(i < (1 shl LG)) {
            for(off in 0..hlen-1) {
                val v = (a[i+hlen+off].toLong()*w[off*step]%MOD).toInt()
                a[i+hlen+off] = a[i+off] - v
                if(a[i+hlen+off] < 0) a[i+hlen+off] += MOD
                a[i+off] = a[i+off] + v
                if(a[i+off] >= MOD) a[i+off] -= MOD
            }
            i += hlen shl 1
        }
        hlen = hlen shl 1
        step = step shr 1
    }
}
 fun wrev() {
    var i=1
    var j=w.lastIndex
    while(i<j) {
        w[i] = w[j].also { w[j] = w[i] }
        ++i; --j
    }
}
 fun idft(a: IntArray) {
    wrev()
 dft(a)
    wrev()
 val mlt = pw((1 shl LG), MOD-2)
 for(i in 0..(1 shl LG)-1) a[i]=(a[i].toLong()*mlt%MOD).toInt()
}
 fun run() {
    initfft()
    val (ntype,nq) = readInts()
    val cost = readInts()
        val s = Array(4*ntype, {IntArray(1 shl LG)})
    fun sbuild(x: Int, l: Int, r: Int, VAL: IntArray) {
        if(l==r) {
            s[x] = VAL.copyOf()
        } else {
            val m=l+(r-l)/2
            sbuild(2*x+1,l,m,VAL); sbuild(2*x+2,m+1,r,VAL)
            for(i in 0..(1 shl LG)-1) s[x][i]=(s[2*x+1][i].toLong()*s[2*x+2][i]%MOD).toInt()
        }
    }
    fun smod(x: Int, l: Int, r: Int, IDX: Int, VAL: IntArray) {
        if(l==r) {
            s[x]=VAL
        } else {
            val m=l+(r-l)/2
            if(IDX<=m) smod(2*x+1,l,m,IDX,VAL) else smod(2*x+2,m+1,r,IDX,VAL)
            for(i in 0..(1 shl LG)-1) s[x][i]=(s[2*x+1][i].toLong()*s[2*x+2][i]%MOD).toInt()
        }
    }
    fun smlt(x: Int, l: Int, r: Int, L: Int, R: Int, VAL: IntArray) {
        if(L<=l&&r<=R) {
            for(i in 0..(1 shl LG)-1) VAL[i]=(VAL[i].toLong()*s[x][i]%MOD).toInt()
        } else {
            val m=l+(r-l)/2
            if(L<=m) smlt(2*x+1,l,m,L,R,VAL)
            if(m+1<=R) smlt(2*x+2,m+1,r,L,R,VAL)
        }
    }
    val nothing = IntArray(1 shl LG){if(it==0) 1 else 0}
    dft(nothing)
    sbuild(0,0,ntype-1,nothing)
        val cnt = IntArray(ntype){0}
        repeat(nq) {
        val args = readInts()
        //println(args.joinToString(" "))
        if(args[0]==1) {
            val (kind,type,delta) = args.mapIndexed{idx,value -> value-(if(idx==1) 1 else 0)}
            //println("kind=$kind type=$type delta=$delta")
            cnt[type] += delta
            var cur = make(cnt[type],cost[type])
            dft(cur)
            smod(0,0,ntype-1,type,cur)
        }
        if(args[0]==2) {
            val (kind,type,delta) = args.mapIndexed{idx,value -> value-(if(idx==1) 1 else 0)}
            cnt[type] -= delta
            var cur = make(cnt[type],cost[type])
            dft(cur)
            smod(0,0,ntype-1,type,cur)
        }
        if(args[0]==3) {
            val (kind,l,r,budget) = args.mapIndexed{idx,value -> value-(if(idx==1||idx==2) 1 else 0)}
            var cur = IntArray(1 shl LG){1}
            smlt(0,0,ntype-1,l,r,cur)
            idft(cur)
            var ans = 0
            for(i in 0..budget) ans = (ans + cur[i])%MOD
            ans=(ans+MOD-1)%MOD
            println(ans)
        }
    }
}
 fun main() {
    run()
}