#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n, t; cin >> n >> t;
    unordered_map<int, vector<int>> mpp;

    for(int i=1; i<n; i++){
        int x, y; cin >> x >> y;
        mpp[x].push_back(y);
        mpp[y].push_back(x);
    }

    vector<bool> visited(n + 1, 0);

    int u; cin >> u;
    queue<pair<int, int>> q;
    q.push({0, u});
    visited[u] = 1;

    int d1 = 0, d2 = 0;
    while(!q.empty()){
        int node = q.front().second;
        int d = q.front().first;

        int cnt = 0;
        for(auto it: mpp[node]){
            if(!visited[it]){
                cnt++;
                visited[it] = true;
                q.push({d + 1, it});
            }
        }

        if(cnt == 0 && d1 == 0){
            d1 = d;
        }else if(cnt == 0){
            d2 = d;
        }

        q.pop();
    }

    if(d1 % 2 == 1 || d2 % 2 == 1){
        cout << "Ron";
    }else{
        cout << "Hermione";
    }
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << 'Case #' << t << ':';
        solve();
    }
}