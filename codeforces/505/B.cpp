//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
using namespace std;
#define int long long
const int N = 117;
vector<int> v[N];
int used[N];
map<pair<int, int>, set<int>> mp;


bool fl = false;
bool dfs(int x,int y,int c) {   
    used[x] = 1;
    for (auto u : v[x]) {
        if (u == y) {
            int x1 = max(x, u);
            int y1 = min(x, u);
            for (auto t : mp[{x1, y1}]) {
                if (t == c) {
                    return true;
                }
            }
        }
        else if (!used[u]) {
            int x1 = max(x, u);
            int y1 = min(x, u); 
            for (auto t : mp[{x1, y1}]) {
                if (t == c) {
                    if (dfs(u, y, c)) {
                        return true;
                    }
                }
            }
        }
        
    }
    return false;
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int m; cin >> m;
    
    set<int> cl;
    for (int i = 0; i < m; ++i) {
        int x, y, c; cin >> x >> y >> c;
        --x; --y;
        v[x].push_back(y);
        v[y].push_back(x);
        cl.insert(c);
        int x1 = max(x, y);
        int y1 = min(x, y);
        mp[{x1, y1}].insert(c);
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        int cnt = 0;
        --x; --y;
        
        for (auto c : cl) {
            fill(used, used + 117, 0);
            fl = false;
            if (dfs(x, y, c)) {
                
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}
