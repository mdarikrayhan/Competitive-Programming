#include <stdio.h>
int t,n,a,b,i;
int main(){

scanf("%d",&t);

for(;t--;a=b=i=0){

scanf("%d",&n);
for(;++i;) 
if(n<i)
{i%4<2?a+=n:b+=n;i=-1;}
else 
i%4<2?a+=i:b+=i,n-=i;
printf("%d %d\n",a,b);

}
}