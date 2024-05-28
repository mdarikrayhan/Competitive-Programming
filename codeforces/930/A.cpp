#include <bits/stdc++.h>
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define trace(x) cerr << #x << " = " << x << '\n'

using namespace std;

template<class T> bool chmax(T& A, T&& B) { return B > A ? A = B, true : false; }
template<class T> bool chmin(T& A, T&& B) { return B < A ? A = B, true : false; }

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int MxN = 2e5 + 5;
vector<int> v[100001];
// vector<bool> vis(100001);
vector<int>p(100001);


void dfs(int node, int dist) {
	// if(vis[node])return;
    // vis[node] = true;
   	p[dist]++;
    for (auto k : v[node]) {
            dfs(k, dist + 1);
    }
 
}

void solve() {
    int n;
    cin >> n;
 
    p.resize(n+1,0);
    for (int i = 1; i <= n; i++) {
        // vis[i] = false;
        v[i].clear();
    }

    for (int i = 2; i <= n; i++) {
        int b;
        cin >> b;
        v[b].pb(i);
    }

    dfs(1, 1);  
   	int ans=0;
   	
   	for(auto i:p){
   		ans+=(i%2);
   		// cout<<i<<' ';
   	}
   	cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
