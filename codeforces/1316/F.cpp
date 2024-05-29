// LUOGU_RID: 157234369
#include <bits/stdc++.h>
#define ll int
using namespace std;

ll pw[300005],a[300005];
struct node {
	ll c00,c01,c10,c11;
} tree[5200005];
ll tot=0,L[5200005],R[5200005],xs[300005],pos[300005],v[300005],rt;
map<ll,ll> cnt,to;
const ll mod=1000000007;

node pushup(node a,node b) {
	node c;
	c.c00=1ll*a.c00*b.c00%mod;
	c.c10=(a.c10+1ll*a.c00*b.c10%mod)%mod;
	c.c01=(b.c01+1ll*a.c01*b.c00%mod)%mod;
	c.c11=(1ll*a.c00*b.c11%mod+1ll*a.c11*b.c00%mod+1ll*a.c10*b.c01%mod)%mod;
	return c;
}

void add(ll &root,ll l,ll r,ll pos,ll v) {
	if (!root)root=++tot;
	if (l==r) {
		cnt[pos]+=v;
		tree[root].c00=pw[cnt[pos]];
		tree[root].c10=tree[root].c01=1ll*to[pos]*(pw[cnt[pos]]-1)%mod;
		if (cnt[pos]>=2) {
			tree[root].c11=1ll*to[pos]*to[pos]%mod*xs[cnt[pos]-2]%mod;
		} else {
			tree[root].c11=0;
		}
//		cout<<l<<","<<r<<":"<<tree[root].c00<<" "<<tree[root].c10<<" "<<tree[root].c01<<" "<<tree[root].c11<< endl;

		return;
	}
	ll mid=(l+r)>>1;
	if (pos<=mid)add(L[root],l,mid,pos,v);
	else add(R[root],mid+1,r,pos,v);
	tree[root]=pushup(tree[L[root]],tree[R[root]]);
//	cout<<l<<","<<r<<":"<<tree[root].c00<<" "<<tree[root].c10<<" "<<tree[root].c01<<" "<<tree[root].c11<< endl;
}

ll qkp(ll a,ll k) {
	ll ans=1;
	while (k) {
		if (k&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		k>>=1;
	}
	return ans;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	pw[0]=1;
	tree[0].c00=1;
	xs[0]=1;
	vector<ll> bk;
	for (ll i=1; i<=n; i++) {
		pw[i]=1ll*pw[i-1]*2%mod;
		xs[i]=(xs[i-1]+1ll*pw[i]*(i+1)%mod)%mod;
		cin >> a[i];
		bk.push_back(a[i]);
	}
	ll q;
	cin >> q;
	for (ll i=1; i<=q; i++) {
		cin >> pos[i]>>v[i];
		bk.push_back(v[i]);
	}
	sort(bk.begin(),bk.end());
	bk.erase(unique(bk.begin(),bk.end()),bk.end());
	for (ll i=0; i<bk.size(); i++)to[i+1]=bk[i];
	for (ll i=1; i<=n; i++) {
		a[i]=lower_bound(bk.begin(),bk.end(),a[i])-bk.begin()+1;
		add(rt,1,n+q,a[i],1);
	}
	ll inv=qkp(qkp(2,n),mod-2)%mod;
	cout<< 1ll*tree[1].c11*inv%mod<<"\n";
	for (ll i=1; i<=q; i++) {
		add(rt,1,n+q,a[pos[i]],-1);
		v[i]=lower_bound(bk.begin(),bk.end(),v[i])-bk.begin()+1;
		a[pos[i]]=v[i];
		add(rt,1,n+q,v[i],1);
		cout<< 1ll*tree[1].c11*inv%mod<<"\n";
	}
	return 0;
}
/*
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　■■■■■　　　　　■■　　　　　　■■■　　　　　■■■　　　■　　　　■　　　　　■　　　　　■■■■　　　　■■■■　　
　■　　　■■　　　　■■　　　　　■　　■■　　　■　　■■　　■　　　　■　　　　■■　　　　　■　　■■　　■■　　■　　
　■　　　　■　　　　■■　　　　■　　　　■　　■　　　　■　　　■　　■　　　　■■■　　　　■■　　■■　　■　　　■■　
　■　　　　■　　　　■■　　　　■　　　　■　　■　　　　■　　　■　　■　　　　　■■　　　　■　　　■■　　　　　　■■　
　■　　　　■　　　　■■　　　　■　　　　　　　■　　　　　　　　　■■　　　　　　■■　　　　　　　　■■　　　　　　■　　
　■　　　■■　　　　■■　　　　■　　■■■　　■　　■■■　　　　■■　　　　　　■■　　　　　　　■■　　　　　■■■　　
　■■■■■　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　　■■　　　　　　　　■■　
　■　　　　　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　■■　　　　　　　　　　■　
　■　　　　　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　■　　　　　　■　　　■■　
　■　　　　　　　　　■■　　　　■■　　■■　　■■　　■■　　　　■■　　　　　　■■　　　　■　　　　　　　■■　　■■　
　■　　　　　　　　　■■　　　　　　■■■■　　　　■■■■　　　　■■　　　　　　■■　　　　■■■■■■　　　■■■■　　
*/