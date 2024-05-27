//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define ss second
#define ff first
#define vt vector
#define uid(a, b) uniform_int_distribution<int>(a, b)(mt)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 2e9;
const int mod = 1e9+7;
const int maxn = 1e6 + 12;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int n, m, x, y;
    cin >> n >> m;
    int d[m];
    for(int i = 0; i < m; i++){
        cin >> d[i];
    }
    cin >> x >> y;
    int dst[m][x];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < x; j++)dst[i][j] = -1;
    }
    dst[0][0] = 0;
    sort(d, d + m);
    queue<pii> q, p;
    q.push({0, 0});
    while(!q.empty()){
        pii nw = q.front();
        q.pop();
        if(nw.ff){
            pii nx = {nw.ff - 1, nw.ss};
            nx.ss += d[nw.ff] - d[nw.ff - 1];
            if(nx.ss <= x){
            nx.ss %= x;
            if(dst[nx.ff][nx.ss] == -1){ 
            dst[nx.ff][nx.ss] = dst[nw.ff][nw.ss];
            if(nx.ss == 0){
                p.push(nx);
                dst[nx.ff][nx.ss]++;
            }
            else q.push(nx);
            }
            }
        }
        if(nw.ff + 1 < m){
            pii nx = {nw.ff + 1, nw.ss};
            nx.ss += d[nw.ff + 1] - d[nw.ff];
            if(nx.ss <= x){
            nx.ss %= x;
            if(dst[nx.ff][nx.ss] == -1){
            dst[nx.ff][nx.ss] = dst[nw.ff][nw.ss];
            if(nx.ss == 0)p.push(nx), dst[nx.ff][nx.ss]++;
            else q.push(nx); 
            }
            }
        }
        if(q.empty())q.swap(p);
    }
    int ans = inf;
    for(int i = m - 1; i >= 0 && d[m - 1] - d[i] <= x; i--){
        if(dst[i][0] != -1){
            ans = min(ans, dst[i][0] * (x + y) + d[m - 1] - d[i]);
        }
    }
    if(ans == inf)ans = -1;
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int times = 1; //cin >> times;
	for(int i = 1; i <= times; i++) {
		solve();
	}
	return 0;
}


