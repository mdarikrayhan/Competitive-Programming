#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=5e5+5;
ll n,x,y,z,b[_],c[_],d[_],sz[_],T,h[_],i;
struct o{ll x,y,z;}a[_];
void p0(ll x,ll y,ll z){a[++T]=(o){h[x],y,z};h[x]=T;}
void p(ll x,ll fa){
	sz[x]=1;ll y,k=0,t=0,i;
	for(i=h[x];i;i=a[i].x)if(a[i].y!=fa){
		y=a[i].y;p(a[i].y,x);sz[x]+=sz[y];
		c[x]+=(c[y]+=a[i].z*2);b[x]+=b[y]+sz[y]*a[i].z;
	}
	for(i=h[x];i;i=a[i].x)if(a[i].y!=fa)d[t++]=a[i].y;
	sort(d,d+t,[](ll x,ll y){return c[x]*sz[y]<c[y]*sz[x];});
	for(i=0;i<t;i++)b[x]+=k*sz[d[i]],k+=c[d[i]];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<n;i++)cin>>x>>y>>z,p0(x,y,z),p0(y,x,z);
	p(1,0);
	cout<<setprecision(9)<<fixed<<b[1]*1./(n-1)<<'\n';
}