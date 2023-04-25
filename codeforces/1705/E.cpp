#include<bits/stdc++.h>
using namespace std;const int N=2e5+7,S=60;typedef long long ll;
ll c[5010];int a[N],n,m,i,j,len;
void A(int x){
	int a=x/S,b=x%S;c[a]+=(1LL<<b);while(c[a]&(1LL<<S))c[a]^=(1LL<<S),c[++a]++;
	if(a>len)len=a;
}
void D(int x){
	int a=x/S;long long b=1ll<<x%S;while(c[a]<b){
		c[a]+=(1LL<<S)-b;a++;b=1;
	}
	c[a]-=b;while(c[len]==0)len--;
}
ll Q(){
	ll ans = len*S;
	ll nw=c[len];while(nw)nw/=2,ans++;
	return ans-1;
}
int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;++i)scanf("%d",a+i),A(a[i]);
	for(;m--;){
		scanf("%d%d",&i,&j);
		D(a[i]);A(a[i]=j);
		printf("%lld\n",Q());
	}
}