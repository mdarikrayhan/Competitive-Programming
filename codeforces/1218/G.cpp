// LUOGU_RID: 159877772
#include<bits/stdc++.h>
using namespace std;
struct nd{
	int u,v,id;
};
int n,m;
int col[500005];
int arr[5];
vector<nd> e;
mt19937 rd(time(0));
vector<pair<int,int> > to[500005];
int fa[500005];
int w[500005];
int ans[500005];
int rt(int x){return fa[x]==x?x:fa[x]=rt(fa[x]);}
int o[500005];
int vst[500005];
int tim=0;
int RT;
void dfs(int x) {
	o[x] = 0;
	vst[x] = 1;
	for (auto [i, j]: to[x])
		if (!vst[i]) {
			dfs(i);
			ans[j] = (arr[col[i]] - o[i] + 3) % 3;
			o[x] = (o[x] + ans[j]) % 3;
		}
}
int U[500005],V[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    char ch;cin>>ch;
		if(ch=='X')col[i]=1;
		else if(ch=='Y')col[i]=2;
		else col[i]=3;
	}
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		u++;v++;
		U[i]=u;V[i]=v;
		to[u].push_back({v,i});
		to[v].push_back({u,i});
	}
	while(1){
		for(int i=1;i<=n;i++)w[i]=0,shuffle(to[i].begin(),to[i].end(),rd),vst[i]=0;
		for(int i=1;i<=m;i++)ans[i]=0;
		arr[1]=1;arr[2]=2;arr[3]=3;
		shuffle(arr+1,arr+4,rd);
		RT=rd()%n+1;
		tim=0;
		dfs(RT);
		bool flg=1;
		for(int i=1;i<=m;i++){
			if(ans[i]==0)ans[i]=3;
			w[U[i]]+=ans[i];
			w[V[i]]+=ans[i];
		}
		for(int i=1;i<=m;i++){
			if(w[U[i]]==w[V[i]])flg=0;
		}
		if(flg){
			for(int i=1;i<=m;i++){
				cout<<U[i]-1<<" "<<V[i]-1<<" "<<(ans[i]==0?3:ans[i])<<endl;
			}
			return 0;
		}
	}
}