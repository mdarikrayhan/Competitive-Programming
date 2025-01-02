// LUOGU_RID: 158393610
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int p=998244353;
inline int _abs(int x){if(x>0) return x;return -x;}

int qpow(int a,int index){
	int ans=1;
	while(index){
		if(index&1) ans=ans*a%p;
		a=a*a%p; index>>=1; 
	}
	return ans;
}

struct node{
	int to,nxt;
}edge[N*2]; int head[N],_cnt;
void add(int u,int v){
	edge[++_cnt].to=v;
	edge[_cnt].nxt=head[u];
	head[u]=_cnt;
}
void adde(int u,int v){
	add(u,v); add(v,u);
}

int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);	
}
void merge(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return;
	fa[x]=y;
}

int col[N],flag;
void dfs(int u){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(col[v]){
			if(col[v]==col[u]){
				flag=1;
				return;
			}
			continue;
		}
		col[v]=3-col[u];
		dfs(v);
		if(flag) return;
	}
}

void fake_main(){
	string s; cin>>s; s=" "+s; int n=s.size()-1;
	int l0=n*2+1,l1=n*2+2;
	int ans=0;
	for(int st=2;st<=n;st++){
		for(int i=1;i<=n*2+2;i++){
			fa[i]=i;
			head[i]=0;
			col[i]=0;
		}
		_cnt=0;
		merge(st,l1);
		merge(n+1,l1);
		for(int i=1;i<st;i++) merge(i,l0);
		for(int i=st;i<=n;i++) merge(i,n-i+st);
		for(int i=1;i<=n;i++) merge(n+i,n*2-i+1);
		for(int i=1;i<=n;i++) if(s[i]=='0') merge(i,n+i);
		adde(find(l0),find(l1));
		for(int i=1;i<=n;i++) if(s[i]=='1') adde(find(i),find(n+i));
		flag=0; int tot=0;
		for(int i=1;i<=n*2+2;i++){
			if(find(i)==i&&!col[i]){
				col[i]=1;
				dfs(i);
				if(flag) break;
				tot++;
			}
		}
		if(flag) continue;
		ans=(ans+qpow(2,tot-1))%p;
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	int t; t=1;
	while(t--) fake_main();
}