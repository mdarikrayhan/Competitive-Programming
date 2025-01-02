#include<bits/stdc++.h>
#define ll long long
#define debug(...) fprintf(stderr, __VA_ARGS__)
template<typename T=int> T rd() {
	int s=0; bool f=1; char c=getchar();
	while(!isdigit(c)) f^=(c=='-'), c=getchar();
	while(isdigit(c)) s=s*10+c-'0', c=getchar();
	return f ? s : -s;
}
using namespace std;
char _begin;
const int N=4e5+5;

int n, a[N], b[N], ap[N], bp[N];
bool vis[N], del[N];

pair<int, bool> L[N], R[N];
#define nxtr(start, i) for(int i=start; i; i=R[i].first, i*=i!=start)

vector<int> lson[N], rson[N];
vector<int> ans;

#define pushL($, x) lson[$].insert(lson[$].begin(), x)
#define pushR($, x) rson[$].insert(rson[$].end(), x)

void dfs(int id) {
	for(int i:lson[id]) dfs(i);
	ans.emplace_back(id);
	for(int i:rson[id]) dfs(i);
}

void calc(int start) {
	queue<int> que;
	nxtr(start, i) {
		if(R[i].second==R[R[i].first].second) {
			que.push(i);
		}
	}
	while(L[start]!=R[start]) {
		if(R[start].first==L[start].first || !que.size()) {
			printf("NO\n");
			exit(0);
		}
		int i=que.front();
		que.pop();
		if(del[i] || R[i].second!=R[R[i].first].second) {
			continue;
		}
		del[R[i].first]=del[R[R[i].first].first]=1;
		if(R[i].second) {
			pushR(i, R[i].first);
			pushR(i, R[R[i].first].first);
		}
		else {
			pushL(i, R[i].first);
			pushL(i, R[R[i].first].first);
		}
		int j=R[R[R[i].first].first].first;//i - Ri - RRi - RRRi
		L[j].first=i;
		R[i]={j, L[j].second^1};
		start=i;
		if(L[i].second!=R[i].second) que.push(L[i].first);
		if(R[i].second==R[R[i].first].second) que.push(i);
	}
	if(R[start].second) {
		dfs(start); dfs(R[start].first);
	}
	else {
		dfs(R[start].first); dfs(start);
	}
}

char _end;
signed main(signed argc, char *argv[]) {
	debug("%lfMB\n", (&_end-&_begin)/1024./1024.);
	n=rd();
	for(int i=1; i<=n*2; i++) {
		a[i]=rd(), b[i]=rd();
		ap[n+a[i]]=i;
		bp[n+b[i]]=i;
	}
	for(int i=1; i<=n*2; i++) if(!vis[i]) {
		for(int j=i; !vis[j];) {
			vis[j]=true;
			int nxa=ap[n-a[j]], nxb=bp[n-b[j]];
			if(!vis[nxa]) {
				R[j]={nxa, a[j]>0};
				L[nxa]={j, a[j]<0};
				j=nxa;
			}
			else {
				R[j]={nxb, b[j]>0};
				L[nxb]={j, b[j]<0};
				j=nxb;
			}
		}
		calc(i);
	}
	printf("Yes\n");
	for(int i:ans) {
		printf("%d %d\n", a[i], b[i]);
	}
	printf("\n");
	return 0;
}