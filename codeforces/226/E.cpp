// LUOGU_RID: 160430676
#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 200005;
	struct node{
		int lson, rson, sz;
	}seg[MAXN << 5];
	int rt[MAXN], Cnt;
	void change(int &x, int l, int r, int w, int y){
		x = ++Cnt;
		seg[x] = seg[y];
		++seg[x].sz;
		if(l == r) return ;
		int mid = l + r >> 1;
		if(mid >= w) change(seg[x].lson, l, mid, w, seg[y].lson);
		else change(seg[x].rson, mid + 1, r, w, seg[y].rson);
	}
	int query(int x, int y, int z, int w, int l, int r, int L, int R){
		if(L <= l && r <= R) return seg[x].sz + seg[y].sz - seg[z].sz - seg[w].sz;
		if(l > R || r < L) return 0;
		int mid = l + r >> 1;
		int lx = seg[x].lson, ly = seg[y].lson, lz = seg[z].lson, lw = seg[w].lson;
		int rx = seg[x].rson, ry = seg[y].rson, rz = seg[z].rson, rw = seg[w].rson;
		return query(lx, ly, lz, lw, l, mid, L, R) + query(rx, ry, rz, rw, mid + 1, r, L, R);
	}
	int head[MAXN], CNT;
	struct edge{
		int next, to;
	}ed[MAXN << 1];
	void add_edge(int u, int v){
		ed[++CNT] = (edge){head[u], v};
		head[u] = CNT;
	}
	int dep[MAXN], f[MAXN][20], a[MAXN];
	int n, m, Rt;
	void dfs(int u){
		dep[u] = dep[f[u][0]] + 1;
		rt[u] = rt[f[u][0]];
		if(a[u]) change(rt[u], 1, m, a[u], rt[u]);
		for(int i = head[u];i;i = ed[i].next){
			int v = ed[i].to;
			dfs(v);
		}
	}
	int kth_fa(int u, int k){
		for(int i = 0;k;i++, k >>= 1){
			if(k & 1) u = f[u][i];
		}
		return u;
	}
	int lca(int u, int v){
		if(dep[u] < dep[v]) swap(u, v);
		u = kth_fa(u, dep[u] - dep[v]);
		if(u == v) return u;
		for(int i = 18;~i;i--){
			if(f[u][i] == f[v][i]) continue;
			u = f[u][i];
			v = f[v][i];
		}
		return f[u][0];
	}
	int getdot(int u, int v, int LCA, int k){
//		printf("%d %d %d %d\n", u, v, LCA, k);
		if(dep[u] - dep[LCA] >= k) return kth_fa(u, k);
		return kth_fa(v, dep[u] + dep[v] - dep[LCA] * 2 - k);
	} 
	struct Q{
		int a, b, k, y, id;
	}q[MAXN];
	int main(){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &f[i][0]);
			if(f[i][0]) add_edge(f[i][0], i);
			else Rt = i;
		}
		int __ = log2(n);
		for(int i = 1;i <= __;i++){
			for(int j = 1;j <= n;j++){
				f[j][i] = f[f[j][i - 1]][i - 1];
			}
		}
		scanf("%d", &m);
		int qnum = 0;
		for(int i = 1, op, x;i <= m;i++){
			scanf("%d", &op);
			if(op == 2){
				qnum++;
				scanf("%d%d%d%d", &q[qnum].a, &q[qnum].b, &q[qnum].k, &q[qnum].y);
				q[qnum].id = i;
			}
			else{
				scanf("%d", &x);
				a[x] = i;
			}
		}
		dfs(Rt);
		for(int i = 1;i <= qnum;i++){
			int u = q[i].a, v = q[i].b, k = q[i].k, y = q[i].y, id = q[i].id;
			int LCA = lca(u, v);
//			int tmp = query(rt[a], rt[b], rt[LCA], rt[f[LCA][0]], 1, m, y + 1, id);
//			if(dep[a] + dep[b] - dep[LCA] * 2 + 1 - tmp < k){
//				puts("-1");
//				continue;
//			}
			int l = 1, r = dep[u] + dep[v] - dep[LCA] * 2 - 1, ans = -1;
			while(l <= r){
				int mid = l + r >> 1;
				int tmp = getdot(u, v, LCA, mid);
//				printf("%d %d\n", mid, tmp);
				int num;
				if(dep[u] - dep[LCA] >= mid){
//					puts("L");
					int mns = query(rt[u], rt[tmp], rt[tmp], rt[f[tmp][0]], 1, m, y + 1, id);
					if(y + 1 <= a[u] && a[u] <= id) mns--;
					num = dep[u] - dep[tmp] - mns;
				}
				else{
					int mns = query(rt[u], rt[tmp], rt[LCA], rt[f[LCA][0]], 1, m, y + 1, id);
					if(y + 1 <= a[u] && a[u] <= id) mns--;
					num = dep[u] + dep[tmp] - dep[LCA] * 2 - mns;
				}
				if(num == k){
					if(y + 1 <= a[tmp] && a[tmp] <= id){
						r = mid - 1;
						continue;
					}
					ans = tmp;
					break;
				}
				if(num > k) r = mid - 1;
				else l = mid + 1;
			}
			printf("%d\n", ans);
		}
		return 0; 
	}
} 
signed main(){
	return Luo_ty::main();
}