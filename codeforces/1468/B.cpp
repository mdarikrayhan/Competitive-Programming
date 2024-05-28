// LUOGU_RID: 160212466
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const __int128 _0=0;
int a[N],c[N],q[N],l[N],r[N],ans[N],n,m,s;
vector<int>e[N];
int calc(int i,int j){return (a[i]-a[j]-1)/(i-j)+1;}
bool check(int i,int j,int k){
	return (_0+a[i]-a[j])*(i-k)<=(_0+a[i]-a[k])*(i-j);
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int _=0;cin>>_;
		a[i]=a[i-1]+_;l[i]=i-1,r[i-1]=i;
	} 
	for(int i=1;i<=m;++i)cin>>c[i];
	for(int i=1;i<n;++i)
	{
		while(s&&check(i,q[s],q[s-1]))--s;
		e[lower_bound(c+1,c+1+m,calc(i,q[s]))-c-1].emplace_back(i);
		q[++s]=i;
	}
	for(int i=m,mx=0;i>=1;--i)
	{
		for(int x:e[i])
		{
			mx=max(mx,r[x]-l[x]-1);
			l[r[x]]=l[x];
			r[l[x]]=r[x];
		}
		ans[i]=mx;
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
