#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 10000000
using namespace std;
int n,Pt,P[N+5],mu[N+5],s[N+5];
int main()
{
	RI i,j;for(scanf("%d",&n),mu[1]=1,i=2;i<=n;++i)
		for(!P[i]&&(mu[P[++Pt]=i]=-1),j=1;i*P[j]<=n;++j) if(P[i*P[j]]=1,++s[j],i%P[j]) mu[i*P[j]]=-mu[i];else break;
	for(i=1;i<=Pt;++i) ++s[i],s[i]+=s[i-1];
	long long t=0;for(i=1;i<=n;++i) t+=1LL*mu[i]*((n/i)-(i==1))*((n/i)-(i==1));t=1LL*(n-1)*(n-2)/2+t/2;
	for(i=1;P[i]*P[i]<=n;++i);for(j=i;i<=Pt;++i) {W(P[i]*P[j]>n) --j;t+=(2*P[i]<=n?1:-2)*(s[i-1]-s[j]);}return printf("%lld\n",t),0;
}