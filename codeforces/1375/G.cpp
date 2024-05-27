// LUOGU_RID: 160013795
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define int long long
#define endl '\n'
#define lowbit(x) (x)&(-x)
#define pii pair<int,int>
#define all(s) s.begin(), s.end()
#define ls(x) (x<<1)
#define rs(x) (x<<1|1) 
#define here system("pause")
using namespace std;
template <class T> inline void read(T& x) { x = 0; char c = getchar(); bool f = 0; for (; !isdigit(c); c = getchar()) f ^= (c == '-'); for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48); x = f ? -x : x; }
template <class T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; if (x < 10) putchar(x + 48); else write(x / 10), putchar(x % 10 + 48); }

const int N = 2e5+5;
const int mod = 1e9+7;
const int INF = 1e9+7;
inline int pow(int a, int b, int p){ int res = 1%p; while(b){ if(b&1) res=res*a%p; a=a*a%p, b>>=1;} return res;}
inline int inv(int a, int p){ return pow(a,p-2,p)%p;}

int n, m, deg[N];
vector<int> g[N];
int h[N];
inline void dfs(int u, int fa, int idx){
	h[idx]++;
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v, u, idx^1);
	}
}

inline void sol(){
	cin >> n;
	for(int i=1;i<n;i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	int rt = 0, mx = 0;
	
	for(int i=1;i<=n;i++){
		if(deg[i]>mx){
			rt = i;
			mx = deg[i];
		}
	}
	
	dfs(1, 0, 0);
	cout << min(h[0], h[1])-1 << endl; 
}

signed main(){
	IOS;
	int tc = 1;
	while(tc--){
		sol();
	}
	return 0;
}
