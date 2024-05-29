n :=File standardInput readLine asNumber
t :=n
h :=0
u :=0
while(t>0,d:=t%10
	if(d==0,u:=1,if(n%d==0,h=1,u=1))
	t=(t/10)floor
)
if(h==1,if(u==1,"happy","happier"),"upset")println
