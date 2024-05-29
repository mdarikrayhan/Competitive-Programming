fun main(arg: Array<String>){
	var s = readLine()!!
	var m = readLine()!!.toLong()
	var l = s.length
	var now = 0.toLong()
	var Q = 1.toLong()
	for(i in 0..l-1){
		now = (now * 10 + (s[i].toInt() - 48))%m
		Q = Q * 10 % m
	}
	var res = now
	for(i in 0..l-1){
		var x = s[i].toInt() - 48
		now = (now * 10 + x - x * Q % m + m)%m
		if(i == l-1 || s[i+1] != '0'){
			if(now < res)res = now
		}
	}
	println(res)
}
