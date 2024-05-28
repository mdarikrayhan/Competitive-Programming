fun main(vararg args: String) {
  val a = readLine()!!.toInt()
  val l = mutableListOf<Int>()
  for (i in 0 until a) {
    val (h, m) = readLine()!!.split(':').map(String::toInt)
    l.add(h*60+m);
  }
  l.sort()
  l.add(l[0]+60*24)
  var dvs = 0;
  for (i in 0 until a) {
    val d = l[i+1]-l[i]-1;
    if (d>dvs)
      dvs = d;
  }
  print("%s:%s\n".format((dvs/60).toString().padStart(2, '0'), (dvs%60).toString().padStart(2, '0')))

}
