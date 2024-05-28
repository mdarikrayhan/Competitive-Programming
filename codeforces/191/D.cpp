#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,as;
vector<int> e[N];
int main(){
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++) as+=e[i].size()&1;
	for(int i=1,u,v;i<=n;i++) if(e[i].size()==2){
		u=e[i][0];v=e[i][1];
		if(u==v) as+=2,e[u].clear();
		else e[u][e[u][0]!=i]=v,e[v][e[v][0]!=i]=u;
	}
	cout<<as/2<<' '<<m;
}