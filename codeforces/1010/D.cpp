// LUOGU_RID: 159807815
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll n,x,y,ct,p[N],t[N],h[N],c[N];
string op;
struct P{ll to,nxt;}e[N];
void add(ll u,ll v){e[++ct]={v,h[u]},h[u]=ct;}
void dfs(ll u,ll fa){
	ll tot=0,s[11];
	for(int i=h[u];i;i=e[i].nxt)
		if(e[i].to!=fa) s[++tot]=e[i].to,dfs(e[i].to,u);
	switch(p[u]){
		case 0:{break;}
		case 1:{
			c[u]=(c[s[1]]&c[s[2]]);
			if(!c[s[1]]) t[s[2]]=1;
			if(!c[s[2]]) t[s[1]]=1;
			break;
		}
		case 2:{c[u]=(c[s[1]]^1);break;}
		case 3:{
			c[u]=(c[s[1]]|c[s[2]]);
			if(c[s[1]]) t[s[2]]=1;
			if(c[s[2]]) t[s[1]]=1;
			break;
		}
		case 4:{c[u]=(c[s[1]]^c[s[2]]);break;}
	}
}
void dfs2(ll u,ll fa){
	t[u]|=t[fa];
	for(int i=h[u];i;i=e[i].nxt)
		if(e[i].to!=fa) dfs2(e[i].to,u);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>x;
		switch(op[0]){
			case 'I':{c[i]=x;break;}
			case 'A':{p[i]=1;cin>>y;add(i,x),add(i,y);break;}
			case 'N':{p[i]=2;add(i,x);break;}
			case 'O':{p[i]=3;cin>>y;add(i,x),add(i,y);break;}
			case 'X':{p[i]=4;cin>>y;add(i,x),add(i,y);break;}	
		}
	}
	dfs(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)
		if(!p[i]) cout<<(t[i]?c[1]:(c[1]^1));
	return 0;
}
