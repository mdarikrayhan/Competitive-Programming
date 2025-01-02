// LUOGU_RID: 158188203
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
const int N=2e5;
int a[N],b[N],u[N],v,w,x,y,z,h,mo;
unordered_map<int,int>F,G;vector<int>D;
inline int ksm(int x,int p,int y=1){for(;p;p/=2,x=x*x%mo)if(p&1)y=x*y%mo;return y;}
signed main(){
	cin>>n>>m>>mo;v=h=mo-1;
	f(i,1,n)scanf("%lld",&a[i]);
	f(i,1,m)scanf("%lld",&l),y=__gcd(y,l);
	for(int i=2;i*i<=v;++i)if(v%i==0)for(u[++w]=i;v%i==0;)v/=i;
	if(v>1)u[++w]=v;
	f(i,1,n){
		x=ksm(a[i],y);z=h;
		f(i,1,w)while(z%u[i]==0&&ksm(x,z/u[i])==1)z/=u[i];
		G[h/z]=1;
	}
	for(int i=1;i*i<=h;++i)if(h%i==0){
		D.push_back(h/i);
		if(i*i<h)D.push_back(i);
	}
	sort(D.begin(),D.end());
	for(int d:D)F[d]=h/d;
	f(i,1,w)for(int d:D)F[d]-=F[d*u[i]];
	f(i,1,w)for(int d:D)G[d*u[i]]|=G[d];
	for(int d:D)s+=F[d]*G[d];
	cout<<s;
	return 0;
}