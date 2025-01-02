// LUOGU_RID: 160060468
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int N = 200005;
struct edges{int to, next, tm;}; edges edge[N << 1];
int n, m, q, cnt, rec[N], ans[N], vis[N], head[N]; queue<int> Q;

void add_edge(int u, int v, int tm){
	edge[++ cnt].to = v; edge[cnt].next = head[u]; edge[cnt].tm = tm; head[u] = cnt;
}
void get(int x){
	if(~ rec[x]) return;
	for(int i = 1; i <= n; i ++) vis[i] = inf;
	while(Q.size()) Q.pop(); vis[1] = 0; Q.push(1);
	while(Q.size()){
		int u = Q.front(); Q.pop();
		for(int v, tm, i = head[u]; ~ i; i = edge[i].next){
			v = edge[i].to; tm = edge[i].tm; if((vis[v] != inf) || (tm > x)) continue; 
			vis[v] = vis[u] + 1; Q.push(v);
		}
	}
	int now = 0;
	for(int i = 1; i <= n; i ++) now = max(now, vis[i]);
	rec[x] = now;
}
int main(){
	memset(rec, -1, sizeof rec);
	memset(head, -1, sizeof head);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= m; i ++){
		int u, v; scanf("%d %d", &u, &v);
		add_edge(u, v, 0); add_edge(v, u, 0);
	}
	for(int i = 1; i <= q; i ++){
		int u, v; scanf("%d %d", &u, &v);
		add_edge(u, v, i); add_edge(v, u, i);
	}
	int i = 0;
	while(i <= q){
		int l = i, r = q, now = i; get(i);
		while(l <= r){
			int mid = (l + r) >> 1; get(mid);
			if(rec[mid] >= (int)ceil(1.0 * rec[i] / 2.0)){now = max(now, mid); l = mid + 1;}
			else r = mid - 1;
		}
		for(int j = i; j <= now; j ++) ans[j] = rec[i];
		i = now + 1;
	}
	for(int i = 0; i <= q; i ++) printf("%d ", ans[i]);
	puts(""); return 0;
}