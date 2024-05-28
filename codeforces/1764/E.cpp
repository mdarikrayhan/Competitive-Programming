// LUOGU_RID: 159855747
#include <cstdio>
#include <algorithm>
#define N 100010
#define ll long long
int n; ll f[N];
struct col
{
	int a,b;
	bool operator<(col c) const
	{
		return a<c.a;
	}
}a[N];
ll min(ll x,ll y) {return x<y?x:y;}
ll max(ll x,ll y) {return x>y?x:y;}
void once()
{
	ll k; scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].a,&a[i].b);
	if(k<=a[1].a) return (void)puts("YES");
	if(n==1||k>a[1].a+a[1].b) return (void)puts("NO");
	ll mx=0;
	std::sort(a+2,a+1+n); for(int i=2;i<=n;i++)
	{
		f[i]=i>2?max(a[i].a,min(a[i].a,f[i-1])+a[i].b):a[i].a;
		f[i]=max(f[i],mx); mx=max(mx,a[i].a+a[i].b);
	}
	puts(f[n]+a[1].b>=k?"YES":"NO");
}
int main()
{
	int T; scanf("%d",&T);
	while(T--) once();
}