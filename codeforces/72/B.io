s	:=""
m	:=Map clone
m	atPut(s, Map clone)
File standardInput readLines foreach(i,v,if(i>0,
	v =v strip
	if(v at(0)==59, continue)
	if(v at(0)==91,
		s =v strip("[ ]")
		m atIfAbsentPut(s, Map clone),
		l := v split("=")
		m at(s) atPut(l at(0) strip,l at(1) strip)
	)
))
m keys sort foreach(v,
	if(v!="",("[".. v .."]") println)
	l := m at(v)
	l keys sort foreach(u,(u .."=".. l at(u))println)
)
