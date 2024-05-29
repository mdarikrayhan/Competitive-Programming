#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f
using std::priority_queue;
const int N=350005;
int n, a[N], l[N], r[N];
priority_queue<ll> L;
priority_queue<ll, std::vector<ll>, std::greater<ll> > R;
ll tl, tr, val, cl, cr;
inline void gmn(int l, int r){
	tl-=r, tr-=l;
	cl-=r, cr-=l;
}
inline void add(int p)
{
	ll l=L.top()+tl, r=R.top()+tr;
	if(l<p&&p<r) L.push(p-tl), R.push(p-tr);
	else if(l>=p) L.push(std::max(cl, 1ll*p)-tl), L.push(std::max(cl, 1ll*p)-tl), L.pop(), R.push(l-tr), val+=l-p;
	else R.push(std::min(cr, 1ll*p)-tr), R.push(std::min(cr, 1ll*p)-tr), R.pop(), L.push(r-tl), val+=p-r;
}
inline ll calc(ll v)
{
	while(!L.empty()) L.pop();
	while(!R.empty()) R.pop();
	val=tl=tr=0;
	L.push(v), R.push(v);
	cl=cr=v;
	for(int i=2; i<=n; ++i) gmn(l[i-1], r[i-1]), add(0);
	gmn(l[n], r[n]);
	val+=std::abs(v);
	while(!R.empty()&&R.top()+tr<v) val+=v-(R.top()+tr), R.pop();
	while(!L.empty()&&L.top()+tl>v) val+=(L.top()+tl)-v, L.pop();
	return val;
}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", a+i, l+i, r+i), l[i]-=a[i], r[i]-=a[i];
	ll l=-35000ll*n, r=35000ll*n;
	while(l<r){
		int mid=(l+r)>>1;
		if(calc(mid)>calc(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n", calc(l));
	return 0;
}