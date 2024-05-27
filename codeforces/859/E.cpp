// LUOGU_RID: 159134363
// #pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
int sz[N];
int pre[N],a[N];
int find(int x){
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
int f[N];
void add(int x,int y){
	x=find(x);
	y=find(y);
	pre[y]=x;
	sz[x]+=sz[y];
	f[x]|=f[y];
	f[y]=0;
	sz[y]=0;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n*2;i++) pre[i]=i,sz[i]=1;
	for(int i=1;i<=n;i+=1){
		int x,y;
		cin>>x>>y;
		a[x]=y;
		if(find(x)==find(y)) f[find(x)]=1;
		else add(x,y);
	}
	n*=2;
	i64 ans=1;
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			sz[find(i)]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==find(i)){
			if(f[i]&&sz[i]>1){
				ans=ans*2%mod;
			}else{
				ans=ans*sz[i]%mod;
			}
		}
	}
	cout<<ans<<endl;

	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}