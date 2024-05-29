// LUOGU_RID: 159462697
#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2005],y[2005];
int n,m;
int ok[45][45],ss[45];
int col[2005],fa[2005],sz[2005];
vector<int>p[105];
int ok1[(1<<20)+5],ok2[(1<<20)+5],pre[(1<<20)+5];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}void merge(int a,int b){
	if(find(a)!=find(b))sz[find(b)]+=sz[find(a)];
	fa[find(a)] = find(b);
}int okk = 1;
void color(int now,int c){
	col[now] = c;
	for(int i =0;i<p[now].size();i++){
		if(!col[p[now][i]])color(p[now][i],3-c);
		else if(col[p[now][i]] == col[now])okk = 0;
	}
}void dfs1(int dep,int s,int S){
	if(dep == n/2){
		ok1[S] = 1;return;
	}if(!(s>>dep&1)){
		dfs1(dep+1,s|ss[dep],S|(1ll<<dep));
	}dfs1(dep+1,s,S);
}int tot = 0;
void dfs2(int dep,int s,int S){
	if(dep == n){
		int tt = 0;
		for(int i =0;i<n/2;i++)tt+=((!(s>>i&1)))<<i;
		tot+=pre[tt];return;
	}if(!(s>>dep&1)){
		dfs2(dep+1,s|ss[dep],S|(1ll<<dep));
	}dfs2(dep+1,s,S);
}int solve_all(){
	return 1ll<<n;
}int solve_0(){
	int tt = 0;
	for(int i = 0;i<n;i++)if(sz[find(i)] == 1)tt++;
	return 1ll<<tt;
}int solve_1(){int tt = 0;
	for(int i = 0;i<n;i++){
		if(fa[i] == i)color(i,1),tt++;
	}if(okk == 0)return 0;return 1ll<<tt;
}int solve_2(){
	int tt =0 ;
	for(int i = 0;i<n;i++){
		if(sz[find(i)] == 1)tt++; 
	}return 1ll<<tt;
}int solve_01(){
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			if(ok[i][j])ss[i]|=1ll<<j; 
		}
	}dfs1(0,0,0);
	memcpy(pre,ok1,sizeof(pre)); 
	for(int i = 0;i<n/2;i++){
		for(int j =0;j<(1<<(n/2));j++){
			if(j>>i&1)pre[j]+=pre[j^(1<<i)];
		}
	}dfs2(n/2,0,0);
	return tot;
}int solve_02(){
	int tt =0 ;
	for(int i = 0;i<n;i++){
		if(find(i) == i)tt++;
	}return 1ll<<tt;
}int solve_012(){
	if(m !=0)return 0;return 1ll<<n;
}
signed main(){
	cin >> n >> m;
	for(int i = 0;i<=n;i++)fa[i] = i,sz[i] = 1;
	for(int i = 1;i<=m;i++){
		int a,b;cin >> a >> b;a--,b--;
		ok[a][b] = ok[b][a] = 1;merge(a,b);
		p[a].push_back(b),p[b].push_back(a);
	}
	int ans = solve_all()-solve_01()*2-solve_02()+solve_0()+solve_1()+solve_2()-solve_012();
	cout << ans << endl; 
	return 0;
}