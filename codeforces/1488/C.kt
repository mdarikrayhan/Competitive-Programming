import kotlin.math.*
 fun main(args:Array<String>)
{
 repeat(readLine()!!.toInt())
 {
  var(n,x,y)=readLine()!!.split(" ").map{ it.toInt() }
  if(x>y)
  {
   x=y.also{ y=x }
  }
  var kte=n*3
  for(i in x until y)
  {
   var tx=i-1+min(x-1,i-x)
   var ty=n-i-1+min(y-i-1,n-y)
   kte=min(kte,max(tx,ty))
  }
  println(kte)
 }
}