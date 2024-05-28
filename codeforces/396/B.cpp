#include<cstdio>
#include<algorithm>
long long T,n,l,r,p,q,g;
int pri(int x){
for(int i=2;i*i<=x;++i)
if(x%i==0)return 1;
return 0;
}
main()
{
scanf("%lld",&T);
for(;T--;)
{
scanf("%lld",&n);
l=r=n;
for(;pri(l);--l);
for(++r;pri(r);++r);
g=std::__gcd(p=l*r+(n-l-r+1)*2,q=2*l*r);
printf("%lld/%lld\n",p/g,q/g);
}
}