// LUOGU_RID: 158891201
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const i64 mod=1e13+7;
int f[N];
int d[N];
vector<pair<int,int>> a[N];
int v[N];
int vis[N];
int len[N];
i64 val[N];
int cnt[N];
int tot;
struct ll{
	int x,d,len,cnt,w;
	i64 va;
	bool friend operator<(const ll a,const ll b){
		if(a.d!=b.d) return a.d>b.d;
		if(val[f[a.x]]==val[f[b.x]]){
			if(a.w==b.w) return a.len>b.len;
			else{
				return a.w>b.w;
			}
		}
		return a.cnt>b.cnt;
	}
};
void solve(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({z,y});
		a[y].push_back({z,x});
	}
	for(int i=0;i<n;i++) sort(a[i].begin(),a[i].end());
	memset(d,-1,sizeof d);
	d[n-1]=0;
	memset(len,0x3f,sizeof len);
	len[n-1]=0;
queue<int>pp;	
	{
	queue<int> q;
	q.push({n-1});
		
	while(q.size()){
		int x=q.front();
		q.pop();
		pp.push(x);
		for(auto [w,y]:a[x]){
			if(w) continue;
			if(d[y]==0) continue;
			d[y]=0;
			len[y]=len[x]+1;
			q.push(y);
			f[y]=x;
		}
	}
	}
	priority_queue<ll> q;
	while(pp.size()){
		int x=pp.front();
		q.push({x,0,len[x],0,0,0});
		pp.pop();
	}
	while(q.size()){
		ll x=q.top();
		q.pop();
		for(auto [w,y]:a[x.x]){
			if(d[y]!=-1){
				if(v[y]<=w) continue;
				if(val[f[y]]==val[x.x]){
					f[y]=x.x;
					len[y]=len[x.x]+1;
					val[y]=(val[x.x]*123+w)%mod;
					v[y]=w;
					q.push({y,d[y],len[y],cnt[y],v[y],val[y]});
				}
				continue;
			}
			cnt[y]=++tot;
			d[y]=d[x.x]+1;
			v[y]=w;
			f[y]=x.x;
			val[y]=(val[x.x]*123+w)%mod;
			q.push({y,d[y],len[y],cnt[y],v[y],val[y]});
		}
	}
	//	return;
	vector<int> o,p;
	int x=0;
	while(x!=n-1){
		o.push_back(x);
		p.push_back(v[x]);
		x=f[x];
	}
	o.push_back(x);
	while(p.size()&&p.back()==0){
		p.pop_back();
	}
	if(p.size()==0) p.push_back(0);
	reverse(p.begin(),p.end());
	
	
	for(auto y:p) cout<<y;
	cout<<endl;
	cout<<o.size()<<endl;
	for(auto y:o) cout<<y<<" ";
	
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