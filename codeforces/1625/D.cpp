#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;

struct node{
	int val;
	int fr;
	friend bool operator <(node a,node b){
		return a.val<b.val;
	}
}f[N],g[N<<5],a[N];

int tr[N<<5][2],cnt=1;
int n,k;

void insert(int val,node x){
	int u=1;
	for(int i=30;i>=0;i--){
		int v=((val>>i)&1);
		if(!tr[u][v]) tr[u][v]=++cnt;
		g[u]=max(g[u],x);
		u=tr[u][v];
	}
	g[u]=max(g[u],x);
}

node query(int val){
	int u=1; node ans={0,0};
	for(int i=30;i>=0;i--){
		if(!u) break;
		int v=((val>>i)&1);
		int now=((k>>i)&1);
		if(!now) ans=max(ans,g[tr[u][v^1]]);
		u=tr[u][v^now];
	}
	if(u) ans=max(ans,g[u]);
	ans.val++; return ans;
}

inline void fake_main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].fr=i;
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		f[i]=query(a[i].val);
		insert(a[i].val,{f[i].val,i});
	}
	int fn=g[1].fr;
	if(f[fn].val==1){
		cout<<"-1\n";
		return;
	}
	cout<<f[fn].val<<"\n";
	for(;fn;fn=f[fn].fr) cout<<a[fn].fr<<" "; 
}

signed main(){
	ios::sync_with_stdio(false);
	int t; t=1;
	while(t--) fake_main();
}
