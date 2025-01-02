concat	:=method(a,b,a .. b)
reverse	:=method(x,x asMutable reverse)
substr	:=method(x,a,b,c,if(c isNil,c=1)
	r	:="" asMutable
	for(i,a-1,b-1,c,r append(x at(i)))
	return r
)
r	:=list()
(" ".. File standardInput readLine .." ")split("\"") foreach(i,v,
		r append(if(i%2==0,v asLowercase,"\"".. v .."\""))
)
writeln("\"",doString(r join("")),"\"")
