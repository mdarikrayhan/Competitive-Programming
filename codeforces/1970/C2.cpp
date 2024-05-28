#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout << '\n';}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a <<  ' ';
	err(++it, args...);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> e[n + 1];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    function<bool(int, int)> dfs = [&] (int u, int fa) {
        bool win = 0;
        for(auto v : e[u]) {
            if(v == fa) continue;
            if(!dfs(v, u)) win = 1;
        }
        return win;
    };  
    while(m--) {
        int s;
        cin >> s;
        cout << (dfs(s, s) ? "Ron\n" : "Hermione\n");
    }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while(t--) solve();
  
    return 0;

}

/*
g++ 1.cpp -std=c++20 -o 1 && 1
*/
