// LUOGU_RID: 160256634
// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename... T2> inline void read(T1 &x, T2 &...y){read(x); read(y...);}

template<typename T> inline void checkmax(T &a, const T &b){if (a<b) a = b;}

template<typename T> inline void checkmin(T &a, const T &b){if (a>b) a = b;}

const int N = 1e5+5, M = 30;
int u[N], v[N], w[N], f[N];
int n, m, q;

struct DSU{
	
	int fa[N], ok[N];
	
	inline void init(){for (int i = 1;i<=n;i++) fa[i] = i, ok[i] = f[i];}
	
	int get_fa(int x){
		if (fa[x] == x) return x;
		return fa[x] = get_fa(fa[x]);
	}
	
	void merge(int x, int y){x = get_fa(x), y = get_fa(y); fa[x] = y, ok[y] |= ok[x];}
	
}d[M];

inline void solve(){
	int x, y; read(x, y);
	for (int i = 0;i<M;i++) if (d[i].get_fa(x) == d[i].get_fa(y)){printf("0\n"); return;}
	for (int i = 1;i<M;i++) if (d[i].ok[d[i].get_fa(x)]){printf("1\n"); return;}
	printf("2\n");
}

int main(){
	read(n, m);
	for (int i = 1;i<=m;i++){
		read(u[i], v[i], w[i]); if (w[i]%2 == 0) f[u[i]] = f[v[i]] = 1;
	}
	for (int i = 0;i<M;i++) d[i].init();
	for (int i = 1;i<=m;i++){
		for (int j = 0;j<M;j++){
			if (w[i]&(1<<j)) d[j].merge(u[i], v[i]);
		}
	}
	read(q);
	while (q--){
		solve();
	}
	return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
 */