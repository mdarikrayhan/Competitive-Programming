#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],c[N];ll ans;vector<int>v[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i),v[a[i]].emplace_back(i);
	for(int i=n,l=1,sl,r=n;i;--i)if(v[i].size()){
		sl=l,l=min(r+1,v[i].front()),r=max(sl-1,v[i].back());
		for(auto p:v[i])for(int x=p;x<=n;x+=x&-x)c[x]++;
		for(int x=r;x;x-=x&-x)ans+=c[x];
		for(int x=l-1;x;x-=x&-x)ans-=c[x];
	}
	return printf("%lld\n",ans),0;
}