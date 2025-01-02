// LUOGU_RID: 159223145
#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 200005;
	struct G{
		int head[MAXN], CNT;
		struct edge{
			int next, to;
		}ed[MAXN];
		void add_edge(int u, int v){
			ed[++CNT] = (edge){head[u], v};
			head[u] = CNT;
		}
	}g1, g2;
	int a[MAXN];
	int deg1[MAXN], deg2[MAXN];
	int L[MAXN], R[MAXN];
	int q[0x66ccff], l, r;
	int n, m, k;
	void topo_sort1(){
		l = r = 0;
		for(int i = 1;i <= n;i++){
			R[i] = a[i] ? a[i] : k;
			if(!deg1[i]) q[++r] = i;
		}
		while(l < r){
			int u = q[++l];
			for(int i = g1.head[u];i;i = g1.ed[i].next){
				int v = g1.ed[i].to;
				deg1[v]--;
				R[v] = min(R[v], R[u] - 1);
				if(!deg1[v]) q[++r] = v; 
			}
		}
	}
	void topo_sort2(){
		l = r = 0;
		for(int i = 1;i <= n;i++){
			L[i] = a[i] ? a[i] : 1;
			if(!deg2[i]) q[++r] = i;
		}
		while(l < r){
			int u = q[++l];
			for(int i = g2.head[u];i;i = g2.ed[i].next){
				int v = g2.ed[i].to;
				deg2[v]--;
				L[v] = max(L[v], L[u] + 1);
				if(!deg2[v]) q[++r] = v; 
			}
		}
	}
	int id[MAXN];
	bool cmp(int a, int b){
		if(L[a] == L[b]) return R[a] < R[b];
		return L[a] < L[b]; 
	} 
	struct S{
		int u, v;
	};
	bool operator < (S a, S b){
		if(a.v == b.v) return a.u < b.u;
		return a.v < b.v;
	}
	set<S> s;
	int main(){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1, u, v;i <= m;i++){
			scanf("%d%d", &u, &v);
			g1.add_edge(u, v);
			g2.add_edge(v, u);
			deg1[v]++;
			deg2[u]++;
		}
		topo_sort1();
		topo_sort2();
//		puts("");
		for(int i = 1;i <= n;i++){
//			printf("%d %d\n", L[i], R[i]);
			if(deg1[i] || L[i] > R[i]){
				printf("-1");
				return 0;
			}
		}
		for(int i = 1;i <= n;i++) id[i] = i;
		sort(id + 1, id + n + 1, cmp);
		int now = 1;
//		puts("");
		for(int i = 1;i <= k;i++){
//			puts("---------------");
//			set<S>::iterator It = s.begin();
//			while(It != s.end()){
//				printf("{%d %d} ", It->u, It->v);
//				It++; 
//			}
//			puts("");
			while(now <= n && L[id[now]] <= i){
				s.insert((S){id[now], R[id[now]]});//set的判重也和重载的运算符有关系... 
//				printf("_%d %d %d_\n", id[now], R[id[now]], s.size());
				now++;
			}
//			printf("\n%d---\n", now);
//			It = s.begin();
//			while(It != s.end()){
//				printf("{%d %d} ", It->u, It->v);
//				It++; 
//			}
//			puts("\n------------");
			set<S>::iterator it = s.begin();
			if((it->v) < i){
				printf("-1");
				return 0;
			}
			if((it->v) > i){
				a[it->u] = i;
//				printf("%d %d\n", it->u, it->v);
				s.erase(it);
				continue;
			}
			while((it->v) == i){
				a[it->u] = i;
//				printf("{%d %d} ", it->u, it->v);
				s.erase(it);
				it = s.begin();
			}
//			puts("");
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		return 0;
	}
} 
int main(){
	return Luo_ty::main();
}