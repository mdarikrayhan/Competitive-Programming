#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int N=1e5+7;
int n,m,a[N],vis[N];
vector<pair<int,int> >v;
vector<int>g[N];
pair<int,int> dfs(int x,int p){
	vis[x]=-1;
	a[x]=!~p;
	vector<pair<int,int> >d;
	for(int i=0,v;i<g[x].size();i++)
		if((v=g[x][i])!=p)
			if(!~vis[v]){
				a[x]++;
				a[v]--;
			}
			else if(!vis[v]){
				pair<int,int> y=dfs(v,x);
				if(!a[v])d.push_back(y);
				else a[x]+=a[v];
			}
	int y;pair<int,int>R;
	if(!d.empty())
		partial_sort(d.begin(),d.begin()+1,d.end());
	if(d.size()&1){
		y=1;
		if(!a[x])R={1,d[0].s};
		else if(d[0].f)
			v.push_back({x,d[0].s});
	}else if(!d.empty()&&!a[x]&&!d[0].f)
		y=2,R={1,d[1].s};
	else R={y=0,x};
	for(int i=y;i<d.size();i+=2)
		v.push_back({d[i].s,d[i+1].s});
	vis[x]=1;
	return R;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;n;cin>>n>>m){
		for(int i=0;i<n;i++)
			vis[i]=0,g[i].clear();
		for(int i=0,k;i<m;i++){
			cin>>k;
			for(int j=0,x,y;j<k;j++,y=x){
				cin>>x;
				if(j)g[x-1].push_back(y-1),
				g[y-1].push_back(x-1);
			}
		}
		v.clear();
		dfs(0,-1);
		cout<<v.size()<<"\n";
		for(int i=0;i<v.size();i++)
			cout<<(v[i].f+1)<<" "<<(v[i].s+1)<<"\n";
	}
	return 0;
}