// LUOGU_RID: 129433452
#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
constexpr int n_MAX=6000+5;
int n,a[n_MAX],b[n_MAX],c[n_MAX],u[n_MAX]; bool w[n_MAX]; int p[n_MAX],q[n_MAX],x[n_MAX<<1],k,y[n_MAX<<1],l,r,skip,beat;
void insert(const int z){x[++k]=z; while((l<=r)&&(b[x[y[r]]]>b[z])) --r; y[++r]=k; if(c[x[k-1]]>a[z]) beat=(k-1);}
void rotate(const int m){rotate(q+1,q+((n-m)-skip)+1,q+(n-m)+1);}
pair<int,long long> simulate(long long sum,const bool prev)
{
	if(prev){if(c[u[1]]>a[u[2]]) return {u[1],sum+1}; rotate(u+1,u+2,u+n+1),++sum;}
	For(i,1,n-1){if(w[i-1]){if(c[u[i-1]]>a[u[i+1]]) return {u[i-1],sum+i}; w[i]=false;} else w[i]=(b[u[i]]>a[u[i+1]]);}
	if(w[n-1]&&(c[u[n-1]]>a[u[w[1]+1]])) return {u[n-1],sum+n};
	int m=0,cur=0; For(i,1,n){if(w[i-1]) p[++m]=i; else q[++cur]=u[i];}
	skip=(n-m),beat=k=0,l=1,r=0; For(i,1,n-m) insert(q[i]);
	For(i,1,m)
	{
		For(j,p[i-1]+1,p[i]-1) insert(u[j]);
		while((l<=r)&&(b[x[y[l]]]<a[u[p[i]]])) skip=min(skip,k-y[l]),++l; if(beat) skip=min(skip,k-beat);
	}
	if(skip==(n-m)) return {-1,-1};
	rotate(m),cur=0; For(i,1,n) if(!w[i-1]) u[i]=q[++cur]; return simulate(sum+((n-1)*skip),w[n-1]);
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n; For(i,0,n-1) cin>>a[i]>>b[i]>>c[i]; iota(u+1,u+n,1); if(a[0]>a[1]) swap(u[1],u[n]);
	const pair<int,long long> ans=simulate(1,false); cout<<ans.first<<' '<<ans.second<<'\n'; return 0;
}