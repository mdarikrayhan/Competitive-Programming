// LUOGU_RID: 158364823
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define pir pair<ll,ll>
#define mkp make_pair
#define pb push_back
using namespace std;
const ll maxn=1010, inf=8e18;
ll n, tot, lf[maxn], vis[maxn];
bitset<maxn> mp[maxn], to[maxn], unlf_mp[maxn], tmp;
int main(){
	scanf("%lld",&n);
	if(n==2) {puts("1 2"); return 0;}
	for(ll i=1;i<=n;i++){
		ll m, x; scanf("%lld",&m);
		tot+=m;
		while(m--){
			scanf("%lld",&x);
			mp[i][x]=1;
		}
	}
	if(tot==n*n){
		for(ll i=2;i<=n;i++) printf("1 %lld\n",i);
		return 0;
	}
	for(ll i=1;i<=n;i++) lf[i]=1;
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++){
			tmp=mp[i]&mp[j];
			if(tmp.count()==2){
				ll x=tmp._Find_first(), y=
				tmp._Find_next(x);
				to[x][y]=to[y][x]=1, lf[x]=lf[y]=0;
			}
		}
	ll cnt=0;
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++)
			if(to[i][j]) printf("%lld %lld\n",i,j), ++cnt;
	if(cnt==1){ ll x=0, y=0;
		for(ll i=1;i<=n;i++)
			if(!lf[i]) vis[i]=1, y=x, x=i;
		for(ll i=1;i<=n;i++)
			if(mp[i].count()<n){
				for(ll j=1;j<=n;j++)
					if(lf[j]&&mp[i][j])
						vis[j]=1, printf("%lld %lld\n",j,x);
				break;
			}
		for(ll i=1;i<=n;i++)
			if(!vis[i]) printf("%lld %lld\n",i,y);
		return 0;
	}
	for(ll i=1;i<=n;i++) unlf_mp[i]=mp[i], to[i][i]=1;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(lf[j]) unlf_mp[i][j]=0;
	for(ll i=1;i<=n;i++)
		if(lf[i]){ ll id=0;
			for(ll j=1;j<=n;j++)
				if(mp[j][i]&&(!id||mp[id].count()>mp[j].count()))
					id=j;
			for(ll j=1;j<=n;j++)
				if(unlf_mp[id]==to[j]){
					printf("%lld %lld\n",i,j);
					break;
				}
		}
	return 0;
}