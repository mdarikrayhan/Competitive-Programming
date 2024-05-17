#include <bits/stdc++.h>
#define ll long long
#define e "\n"
#define all(v) ((v).begin()), ((v).end())
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
using namespace std;
const int MAXN = 2e5 + 5;
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
const int MAXX=1e17;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int node, int parent, int depth) {
    dist[node] = depth;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, depth + 1);
        }
    }
}
void solve(){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        t[x][y] = t[y][x] = 1;
    }

    int ans = INT_MAX;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == k || j == k || i == j)
                    continue;
                if (t[i][k] && t[j][k] && t[i][j]) {
                    ans = min(ans, a[i] + a[j] + a[k]);
                }
            }
        }
    }

    if (ans == INT_MAX)
        cout << "-1"<<e;
    else
        cout << ans<<e;
    
}
int main() {
    int t=1;
    //cin >> t;
    while (t--) {
         solve();
    }
    return 0;
}
