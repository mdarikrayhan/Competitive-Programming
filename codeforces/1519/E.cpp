// LUOGU_RID: 159934078
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,tot;
int vst[600005],del[600005];
map<pair<int,int>,int> g;
vector<int> son[600005];
int cnt=0;
vector<pair<int,int>> jqh;
void dfs(int x,int fa){
	vst[x]=1,cnt+=x<=n;
	vector<int> d;
	for(int y:son[x]){
		if(!vst[y]){
			dfs(y,x);
			if(x>n&&!del[y])d.push_back(y);
		}
	}
	if(x>n){
		for(int i=0;i+1<d.size();i+=2)jqh.push_back({d[i],d[i+1]});
		if(d.size()&1){
			if(fa&&!del[fa])jqh.push_back({d.back(),fa}),del[fa]=1;
		}
	}
}
pair<int,int> get(int A,int B){
	int g=__gcd(A,B);
	return {A/g,B/g};
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,tot=n;
	for(int i=1;i<=n;i++){
		int a,b,c,d;cin>>b>>a>>d>>c;
		auto A=get(a*d,c*(a+b));
		auto B=get(a*(c+d),b*c);
		if(g.find(A)==g.end())g[A]=++tot;
		if(g.find(B)==g.end())g[B]=++tot;
		son[i].push_back(g[A]),son[g[A]].push_back(i);
		son[i].push_back(g[B]),son[g[B]].push_back(i);
	}
	int ans=0;
	for(int i=n+1;i<=tot;i++){
		if(!vst[i]){
			cnt=0,dfs(i,0);
			ans+=cnt/2;
		}
	}
	cout<<ans<<endl;
	for(auto tmp:jqh)cout<<tmp.first<<' '<<tmp.second<<endl;
	return 0;
}