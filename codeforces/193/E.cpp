#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,k)for(ll i=(j);i<=(k);i++)
#define pii pair<ll,ll>
#define fi first
#define se second
ll n,l,md;
vector<ll> z[20];
ll mul(ll a,ll b){ll d=((__int128)a*b)%md;
	if(d<0)d+=md;return d;
}
pii sol(ll x){pii t;
	if(x==0)return {0,1};
	if(x&1){t=sol(x-1);return {t.se,(t.fi+t.se)%md};}
	t=sol(x/2);return {mul(t.fi,2*t.se-t.fi),(mul(t.fi,t.fi)+mul(t.se,t.se))%md};
}
int main(){scanf("%lld",&n);
	l=60;md=10;
	rep(i,0,l-1)if(sol(i).fi==n%md)z[0].push_back(i);
	rep(i,0,11){md*=10;
		for(ll j:z[i])rep(k,0,9)
			if(sol(j+k*l).fi==n%md)z[i+1].push_back(j+k*l);l*=10;
	}sort(z[12].begin(),z[12].end());
	if(!z[12].size())puts("-1");
	else printf("%lld\n",z[12][0]);
}