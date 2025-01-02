#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e6 + 10;
int dis[N], par[N];
vector<int> adj[N], V;
int n, ans = 1e18;
void bfs(int v){
    dis[v] = 0, par[v] = -1;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (auto x : adj[u]){
            if (x == par[u])
                continue;
            if (dis[x] == 1e18){
                dis[x] = dis[u] + 1;
                par[x] = u;
                Q.push(x);
            }
            else
                ans = min(ans, dis[u] + dis[x] + 1);
        }
        V.pb(u);
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= 1000; j++)
            while (arr[i] % (j * j) == 0)
                arr[i] /= (j * j);
    for (int i = 1; i <= n; i++)
        for (int j = (int)((sqrt(arr[i]) + 1)); j; j--)
            if (arr[i] == 1)
                return cout << 1, 0;
            else if (arr[i] % j == 0){
                adj[arr[i] / j].pb(j);
                adj[j].pb(arr[i] / j);
                break;
            }
    for (int i = 0; i < N; i++)
        par[i] = -1, dis[i] = 1e18;
    for (int i = 1; i <= 1000; i++){
        for (auto u : V)
            dis[u] = 1e18, par[u] = -1;
        V.clear();
        bfs(i);
    }
    return cout << (ans == 1e18 ? -1 : ans), 0;
}