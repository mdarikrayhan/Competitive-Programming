#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m,p,q;
string mp[N];
ll dis[N];
vector<pair<int,int> >G[N];
priority_queue<pair<ll,int> >Q;
inline int id(int i,int j){if(!i||!j||i>n||j>m||mp[i][j-1]=='#')return -1;return (i-1)*m+j;}
inline void adde(int u,int v,int w){if(u<0||v<0)return;G[u].push_back(make_pair(v,w));}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>p>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)cin>>mp[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j-1]=='L')adde(id(i-1,j+1),id(i,j),p),adde(id(i+1,j+1),id(i,j),p),adde(id(i,j+2),id(i,j),q);
			if(mp[i][j-1]=='R')adde(id(i-1,j-1),id(i,j),p),adde(id(i+1,j-1),id(i,j),p),adde(id(i,j-2),id(i,j),q);
			if(mp[i][j-1]=='U')adde(id(i+1,j-1),id(i,j),p),adde(id(i+1,j+1),id(i,j),p),adde(id(i+2,j),id(i,j),q);
			if(mp[i][j-1]=='D')adde(id(i-1,j-1),id(i,j),p),adde(id(i-1,j+1),id(i,j),p),adde(id(i-2,j),id(i,j),q);
			if(mp[i][j-1]=='.')Q.push(make_pair(dis[id(i,j)]=0,id(i,j)));
		}
	}
	while(!Q.empty()){
		int x=Q.top().second;Q.pop();
		for(auto e:G[x]){
			int y=e.first,z=e.second;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				Q.push(make_pair(-dis[y],y));
			}
		}
	}
	ll ans=1e18;
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)if(id(i,j)>=0&&id(i,j+1)>=0)ans=min(ans,dis[id(i,j)]+dis[id(i,j+1)]);
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)if(id(i,j)>=0&&id(i+1,j)>=0)ans=min(ans,dis[id(i,j)]+dis[id(i+1,j)]);
	cout<<(ans==1e18?-1:ans)<<'\n';
}