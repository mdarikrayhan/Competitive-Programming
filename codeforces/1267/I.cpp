#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define N 3
void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector G(n + 1, vector(n + 1, -1));
    vector<int> ve[N];
    int pos[N] = {0, 0, 0};
    auto ask = [&](int x, int y) -> bool {
        if(x == y) return 1;
        if(G[x][y] != -1) return G[x][y];
        cout << "? " << x << ' ' << y << endl;
        string s;
        cin >> s;
        if(s == "<") G[x][y] = 1;
        else G[x][y] = 0;
        G[y][x] = !G[x][y];
        return G[x][y];
    };
    auto query = [&](int x, int y) {
        return ask(ve[x][pos[x]], ve[y][pos[y]]);
    };
    if(n == 6) {
        for(int i = 1; i <= n; i++) {
            ve[i % 3].push_back(i);
        }
        for(int i = 0; i < 3; i++) {
            sort(ve[i].begin(), ve[i].end(), ask);
        }
        vector<int> comp = {1, 2, 0};
        sort(comp.begin(), comp.end(), query);
        pos[comp[0]]++;
        int id[3] = {comp[2], comp[0], comp[1]};
        if(query(id[1], id[2]) == 1) {
            pos[id[1]]++;
            query(id[0], id[2]);
        } else {
            pos[id[2]]++;
            if(query(id[1], id[2]) == 1) {
                swap(id[1], id[2]);
            }
            query(id[0], id[2]);
        }
        cout << "!" << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        ve[i % N].push_back(i);
    }
    for(int i = 0; i < N; i++) {
        sort(ve[i].begin(), ve[i].end(), ask);
    }
    for(int c = 0; c < n / 2; ) {
        #define sz(x) (int(ve[x].size()) - pos[x])
        int id[3] = {0, 1, 2};
        sort(id, id + 3, [&](int x, int y) { return sz(x) > sz(y); });
        if(sz(id[2]) == 1) {
            if(query(id[0], id[1])) {
                swap(id[0], id[1]);
            }
            int state = 1;
            while (c < n / 2) {
                switch(state) {
                    case 1:
                        if(query(id[1], id[2])) { // C > B
                            pos[id[1]]++, c++, state = 2;
                        } else {
                            pos[id[2]]++, c++, state = -1;
                        }
                        break;
                    case 2:
                        if(sz(id[0]) < sz(id[1])) {
                            swap(id[0], id[1]);
                        }
                        if(query(id[1], id[2])) { // C > B
                            state = 3;
                        } else {
                            state = 4;
                        }
                        break;
                    case 3:
                        if(query(id[0], id[1])) { // B > A
                            pos[id[0]]++, c++, state = -1;
                        } else {
                            pos[id[1]]++, c++, state = 2;
                        }
                        break;
                    case 4:
                        if(query(id[0], id[2])) { // C > A
                            pos[id[0]]++, c++, state = -1;
                        } else {
                            pos[id[2]]++, c++, state = -1;
                        }
                    default:
                        break;
                }
                for(int i = 0; i < 3; i++) {
                    if(sz(i) == 0) {
                        state = -1;
                    }
                }
                if(state == -1) {
                    break;
                }
            }
            continue;
        }
        vector<int> comp;
        for(int i = 0; i < N; i++) {
            if(sz(i) != 0) {
                comp.push_back(i);
            }
        }
        sort(comp.begin(), comp.end(), query);
        pos[comp[0]]++, c++;
    }
    cout << "!" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}