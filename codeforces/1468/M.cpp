// LUOGU_RID: 159727482
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+5;
int _,n,x,y,tot,b,fl[N];
bool cdl;
vector<int> ve[N];
map<int,int> mp;
struct node{int v,p;};
vector<node> w[N];
inline int read(){
	int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
inline int val(int x){if(!mp[x])mp[x]=++tot;return mp[x];}
signed main(){
	_=read();
	while(_--){
		n=read();tot=b=0,cdl=false,mp.clear();
		for(int i=1;i<=n;i++){x=read(),b+=x,ve[i].clear();while(x--)ve[i].pb(val(read()));}
		b=sqrt(b)/2;
		for(int i=1;i<=n&&!cdl;i++)if((int)ve[i].size()>b){
			for(int v:ve[i])fl[v]=1;
			for(int j=1;j<=n&&!cdl;j++)if(j!=i){
				x=0;for(int vv:ve[j])x+=fl[vv];
				if(x>=2)printf("%d %d\n",i,j),cdl=true;
			}
			for(int v:ve[i])fl[v]=0;
		}
		if(cdl)continue;
		for(int i=1;i<=tot;i++)w[i].clear();
		for(int i=1;i<=n;i++)if((int)ve[i].size()<=b)for(int u:ve[i])for(int v:ve[i])if(u<v)w[u].pb({v,i});
		for(int i=1;i<=tot&&!cdl;i++){
			for(node p:w[i]){
				if(fl[p.v]){printf("%d %d\n",fl[p.v],p.p),cdl=true;break;}
				fl[p.v]=p.p;
			}
			for(node p:w[i])fl[p.v]=0;
		}
		if(!cdl)puts("-1");
	}
	return 0;
}