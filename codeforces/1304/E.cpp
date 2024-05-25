// LUOGU_RID: 159768156
#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,m,lg;
int dep[N],f[N][22];
int h[N],e[N],ne[N],idx;

void add(int a,int b) {
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int depth) {
	dep[u]=depth;
	for(int i=h[u]; i!=-1; i=ne[i]) {
		int j=e[i];
		if(j==f[u][0]) continue;
		f[j][0]=u;
		for(int k=1; k<=lg; k++)
			f[j][k]=f[f[j][k-1]][k-1];
		dfs(j,depth+1);
	}
}

int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=lg; i>=0; i--)
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=lg; i>=0; i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int dist(int x,int y) {
	int p=lca(x,y);
	return dep[x]+dep[y]-2*dep[p];
}

bool check(int x,int y) {
	if(x>y) return 0;
	return 1-(y-x)%2;
}

int main() {
	memset(h,-1,sizeof h);
	cin >> n;
	lg=(int)(log(n)/log(2))+1;
	for(int i=1; i<=n-1; i++) {
		int a,b;
		cin >> a >> b;
		add(a,b),add(b,a);
	}
	dfs(1,1);
	cin >> m;
	for(int i=1; i<=m; i++) {
		int x,y,a,b,k;
		cin >> x >> y >> a >> b >> k;
		int d1=dist(a,b);
		int d2=dist(a,x)+dist(y,b)+1;
		int d3=dist(a,y)+dist(x,b)+1;
		bool flag=0;
		flag|=check(d1,k);
		flag|=check(d2,k);
		flag|=check(d3,k);
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}