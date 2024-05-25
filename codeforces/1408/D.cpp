// LUOGU_RID: 160023486
#include <bits/stdc++.h>
using namespace std;
const int N=2005,M=1e6+5;
int a[N],b[N],c[N],d[N],f[M];
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	for(int i=1;i<=m;++i)cin>>c[i]>>d[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i]>c[j]||b[i]>d[j])continue;
			f[c[j]-a[i]]=max(f[c[j]-a[i]],d[j]-b[i]+1);
		}
	}
	for(int i=1e6;i>=0;--i)f[i]=max(f[i],f[i+1]);
	int res=1e9;
	for(int i=0;i<=1e6;++i)res=min(res,i+f[i]);
	cout<<res<<'\n';
	return 0;
}