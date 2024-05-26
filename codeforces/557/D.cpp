// LUOGU_RID: 160090257
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,m,u,v,ans,a[N],ct1,ct2;
vector<ll> e[N];
bool flag;
void add(ll u,ll v){e[u].push_back(v);}
bool dfs(ll u,ll c){
	if(a[u]!=-1) return a[u]!=c;
	a[u]=c;
	if(c) ct1++;
	else ct2++;
	bool res=0;
	for(auto v:e[u]) res|=dfs(v,c^1);
	return res;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(!m){
		cout<<"3 "<<n*(n-1)*(n-2)/6;
		return 0;
	}
	for(int i=1;i<=m;i++) cin>>u>>v,add(u,v),add(v,u);
	for(int i=1;i<=n;i++) a[i]=-1;
	for(int i=1;i<=n;i++)
		if(a[i]==-1){
			ct1=ct2=0;
			if(dfs(i,0)){
				cout<<"0 1";
				return 0;
			}
			if(ct1+ct2>2) flag=1,ans+=ct1*(ct1-1)/2+ct2*(ct2-1)/2;
		}
	if(flag) cout<<"1 "<<ans;
	else cout<<"2 "<<(n-2)*m; 
	return 0;
}
