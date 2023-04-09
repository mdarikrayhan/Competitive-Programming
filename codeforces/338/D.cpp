#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005];
void exgcd(ll a,ll b,ll &x,ll &y){if(!b)return x=1,y=0,void();exgcd(b,a%b,y,x);y-=(a/b)*x;}
int main()
{
	ll n,m,x,l=0,r=0;int k;
	cin>>n>>m>>k>>a[0];l=a[0];r=0;
	for(int i=1;i<k;i++)
	{
		cin>>a[i];ll t=__gcd(l,a[i]);
		if(1.0*l/t*a[i]>1e13||l/t*a[i]>n||(-i-r)%t){puts("NO");return 0;}
		ll p,q,m=l/t*a[i];exgcd(l/t,a[i]/t,p,q);
		r=(r+(ll)((__int128)p*(-i-r)/t%m*l%m)+m)%m;l=m;
	}
	if(!r)r=l;
	if(l>n||r+k-1>m){puts("NO");return 0;}
	for(int i=0;i<k;i++)if(__gcd(l,r+i)!=a[i]){puts("NO");return 0;}
	puts("YES");
	return 0;
}