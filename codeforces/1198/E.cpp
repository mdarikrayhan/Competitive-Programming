#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;

int siz,n;

array<int,4> a[55];

vector<int> px,py;

int N,M;

int sta[205][205];

int h[405],e[100005],ne[100005],idx;

ll w[100005];

int S,T;

void add(int a,int b,ll c) {
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

inline void addEdge(int u,int v,ll w) {
	add(u,v,w),add(v,u,0);
}

int start[405],dep[405];

int q[405],head=0,tail=-1;

bool bfs() {
	memset(dep,-1,sizeof(int)*(T+1));
	head=0,tail=-1,dep[S]=0,start[S]=h[S];
	q[++tail]=S;
	while(head<=tail) {
		int u=q[head++];
		for(int i=h[u];i!=-1;i=ne[i]) {
			int v=e[i];
			if(w[i]>0 && dep[v]==-1) dep[v]=dep[u]+1,start[v]=h[v],q[++tail]=v;
		}
	}
	return dep[T]!=-1;
}

ll dfs(int u,ll flow) {
	if(u==T) return flow;
	ll res=0;
	for(int &i=start[u];i!=-1;i=ne[i]) {
		int v=e[i];
		if(w[i]>0 && dep[v]==dep[u]+1) {
			ll backflow=dfs(v,min(flow,w[i]));
			w[i]-=backflow,w[i^1]+=backflow,res+=backflow,flow-=backflow;
			if(flow==0) break;
		}
	}
	if(res==0) dep[u]=-1;
	return res;
}

ll Dinic() {
	ll res=0;
	while(bfs()) res+=dfs(S,inf);
	return res;
}

int main() {
	scanf("%d %d",&siz,&n);
	for(int i=1;i<=n;i++) {
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		px.push_back(a[i][0]-1);
		px.push_back(a[i][0]);
		
		py.push_back(a[i][1]-1);
		py.push_back(a[i][1]);
		
		px.push_back(a[i][2]);
		px.push_back(a[i][2]+1);
		
		py.push_back(a[i][3]);
		py.push_back(a[i][3]+1);
	}
	sort(px.begin(),px.end()),sort(py.begin(),py.end());
	px.erase(unique(px.begin(),px.end()),px.end()),py.erase(unique(py.begin(),py.end()),py.end());
	N=px.size(),M=py.size();
	for(int i=1;i<=n;i++) {
		a[i][0]=lower_bound(px.begin(),px.end(),a[i][0])-px.begin()+1;
		a[i][1]=lower_bound(py.begin(),py.end(),a[i][1])-py.begin()+1;
		a[i][2]=lower_bound(px.begin(),px.end(),a[i][2])-px.begin()+1;
		a[i][3]=lower_bound(py.begin(),py.end(),a[i][3])-py.begin()+1;
		for(int j=a[i][0];j<=a[i][2];j++) {
			for(int k=a[i][1];k<=a[i][3];k++) sta[j][k]=1;
		}
	}
	S=0,T=N+M+1;
	memset(h,-1,sizeof(int)*(T+1));
	for(int i=1;i<=N;i++) addEdge(S,i,px[i]-px[i-1]);
	for(int i=1;i<=M;i++) addEdge(i+N,T,py[i]-py[i-1]);
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(sta[i][j]) addEdge(i,j+N,inf);
		}
	}
	printf("%lld",Dinic());
	return 0;
}
