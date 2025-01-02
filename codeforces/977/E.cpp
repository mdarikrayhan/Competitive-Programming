#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define clr(x,val) memset((x),(val),sizeof(x)) 
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
ll Ceil(ll a, ll b) { return (a + (b - 1)) / b; }
void hhh() {//freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
}
int dx[] = { 0,0,-1,1,-1,1,-1,1 };
int dy[] = { 1,-1,0,0,-1,-1,1,1 };
bool getBit(ll num, int idx) { return ((num >> idx) & 1); }
ll setBit(ll num, int idx, bool val) { return val ? (num | (1LL << idx)) : (num & ~(1LL << idx)); }
ll flipBit(ll num, int idx) { return (num ^ (1LL << idx)); }
ll count_ones(ll n) { ll cnt = 0; while (n) { cnt++, n &= n - 1; }return cnt; }
int n, m;
vector<vector<int>>adj;
vector<int>vis;
bool can = 1;
void dfs(int node) {
    vis[node] = 1;
    can &= adj[node].size() == 2;
    for (auto& it : adj[node]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}
int main() {
    hhh();
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<int>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (can)cnt++;
        }
        can = 1;
    }
    cout << cnt;
    return 0;
}