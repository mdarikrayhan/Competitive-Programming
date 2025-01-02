// LUOGU_RID: 143762841
#include<bits/stdc++.h>
using namespace std;
long long n,sum,a,b,f[100],cnt;
inline bool ins(long long x)
{
	for(int i=65;i>=0;--i)
		if(x>>i&1)
			if(f[i]) x^=f[i];
			else return f[i]=x,++cnt,1;
	return 0;
 } 
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld%lld",&a,&b),sum^=a,ins(a^b);
	if(ins(sum)) puts("1/1");
	else printf("%lld/%lld\n",(1ll<<cnt)-1,1ll<<cnt);
	return 0;
}