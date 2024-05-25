// LUOGU_RID: 160171603
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005];
int dfs(int l,int r){
	if(l==r) return min(1ll,a[l]);
	int minn=1e18,sum=0,w;
	for(int i=l;i<=r;i++) minn=min(minn,a[i]);
	for(int i=l;i<=r;i++) a[i]-=minn;
	for(int i=l;i<=r;i++){
        if(!a[i]) continue;
        w=i;
        while(a[w]&&w<=n) w++;
        w--;
        sum+=dfs(i,w);
        i=w;
	}
	return min(r-l+1,sum+minn);
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dfs(1,n);
}