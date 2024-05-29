n :=File standardInput readLine asNumber
p :=0
m :=n
while(n>0,for(x,n,1,-1,
q :=0
for(i,2,x-1,if(x%i==0,q :=1;break;))
if(q==0,
if(p==1,"+" print)
p :=1
n :=n-x
x print
break
)
))
"=" print
m println