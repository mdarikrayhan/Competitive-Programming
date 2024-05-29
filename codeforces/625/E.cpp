#include<bits/stdc++.h>
#define B begin()
#define I insert
#define E erase
#define W(i) {d(i,r[i]),i}
using namespace std;
typedef long long ll;
const ll _=1e5+5,F=2e9;
ll n,m,a[_],p[_],b[_],l[_],r[_];
set<pair<ll,ll> >s;
ll d(ll x,ll y){
	if(x==y)return F;
	ll e=(p[y]-p[x]+m)%m;
	if(x>y)e=(e+a[y])%m;
	if(e<=a[x])return 1;
	if(a[x]<=a[y])return F;
	return (e-a[y]-1)/(a[x]-a[y])+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>p[i]>>a[i],p[i]--,b[i]=i;
	sort(b,b+n,[](ll s,ll t){return p[s]<p[t];});
	for(ll i=0;i<n;i++)l[b[i]]=b[(i+n-1)%n],r[b[i]]=b[(i+1)%n],s.I(W(b[i]));
	while(!s.empty()){
		if(s.B->first==F)break;
		ll i=s.B->second;
		s.E(s.B);s.E(W(l[i]));s.E(W(r[i]));
		p[i]=(p[i]+d(i,r[i]))%m;a[i]--;l[r[i]=r[r[i]]]=i;
		s.I(W(l[i]));s.I(W(i));
	}
	cout<<s.size()<<'\n';
	for(auto x:s)cout<<x.second+1<<' ';
	return 0;
} //2992451443306046571