#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m;
int rd[N],f[N],in[N],fl[N];
pair<int,int>s[N];
vector<int>e[N],v[N];
signed main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)rd[i]=in[i]=fl[i]=0,f[i]=1e9,e[i].clear();
		for(int i=1,x,y;i<=m;++i)cin>>x>>y,e[y].push_back(x),v[x].push_back(y),++rd[x];
		queue<int>q;
		q.push(1),in[1]=true,f[1]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			in[x]=false,fl[x]=true;
			for(int y:e[x]){
				fl[y]=true;
				if(f[y]>f[x]+1){
					f[y]=f[x]+1;
					if(!in[y])q.push(y);
				}
			}
		}
		bool bl=false;
		for(int i=1;i<=n;++i)if(!fl[i])bl=true;
		if(bl){cout<<"INFINITE\n";continue;}
		cout<<"FINITE\n";
		int res=0;
		for(int i=1;i<=n;++i)res+=f[i],s[i]=make_pair(f[i],i);
		cout<<res<<"\n";
		sort(s+1,s+n+1);
		for(int i=1;i<=n;++i){
			for(int j=n;j>=1;--j)if(s[j].first>=i)cout<<s[j].second<<" ";
		}
		cout<<"\n";
	}
	return 0;
}