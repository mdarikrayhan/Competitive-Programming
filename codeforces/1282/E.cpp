#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5+5;

int n,a[N],b[N],c[N],in[N],vis[N];
vector<int> g[N],pth,g2[N];
queue<int> q;

void dfs(int u,int fa){
//	cout<<u<<","<<fa<<endl;
	pth.push_back(u);
	if (pth.size()==n){
		return;
	}
	for (auto v : g[u]){
		if (v^fa){
			dfs(v,u);
			break;
		}
	}
}

void del(int x){
	in[x]--;
	if (in[x]==1){
		int p=0;
		for (auto v : g2[x]){
			if (!vis[v]){
				p=v;
			}
		}
		if (p){
			q.push(p);
			vis[p]=1;
		}
	}
}

void solve(){
	cin>>n;
	map<pair<int,int>,int> mp;
	pth.clear();
	for (int i=1; i<=n; i++){
		g[i].clear();
		vis[i]=0;
		g2[i].clear();
		in[i]=0;
	}
	for (int i=1; i<=n-2; i++){
		cin>>a[i]>>b[i]>>c[i];
		mp[{a[i],b[i]}]++;
		mp[{a[i],c[i]}]++;
		mp[{b[i],c[i]}]++;
		mp[{b[i],a[i]}]++;
		mp[{c[i],a[i]}]++;
		mp[{c[i],b[i]}]++;
		in[a[i]]++,in[b[i]]++,in[c[i]]++;
		g2[a[i]].push_back(i);
		g2[b[i]].push_back(i);
		g2[c[i]].push_back(i); 
	}
	for (int i=1; i<=n-2; i++){
		if (mp[{a[i],b[i]}]==1){
		//	cout<<a[i]<<"-"<<b[i]<<endl;
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		if (mp[{a[i],c[i]}]==1){
		//	cout<<a[i]<<"-"<<c[i]<<endl;
			g[a[i]].push_back(c[i]);
			g[c[i]].push_back(a[i]);
		}
		if (mp[{b[i],c[i]}]==1){
		//	cout<<b[i]<<"-"<<c[i]<<endl;
			g[b[i]].push_back(c[i]);
			g[c[i]].push_back(b[i]);
		}	
	}
	//system("pause");
	dfs(1,0);
	vector<int> ans;
	for (int i=1; i<=n; i++){
		if (in[i]==1){
			if (!vis[g2[i][0]]){
				q.push(g2[i][0]);
				vis[g2[i][0]]=1;
			}
		}
	}
	while (!q.empty()){
		int x=q.front();
		q.pop();
		ans.push_back(x);
		del(a[x]);
		del(b[x]);
		del(c[x]);
	}
	for (auto u : pth){
		cout<<u<<" ";
	}
	cout<<"\n";
	for (auto u : ans){
		cout<<u<<" ";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while (t--){
		solve();
	}
	return 0;
}
