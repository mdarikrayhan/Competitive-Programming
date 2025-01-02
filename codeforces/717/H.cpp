#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
 
const int N = 50'000 + 7, E = 100'000 + 7, T = 1'000'000 + 7;
vector<int> wish[N];
int n, m, t, team[N], conf[T];
pii hate[E];
 
void distribute() {
    for (int i = 1; i <= n; i++)
        team[i] = wish[i][rand() % wish[i].size()];
    for (int i = 1; i <= t; i++)
        conf[i] = rand() % 2 + 1;
}
 
bool check() {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        auto [v, u] = hate[i];
        if (conf[team[v]] != conf[team[u]])
            cnt++;
    }
    return cnt >= (m + 1) / 2;
}
 
void print() {
    for (int i = 1; i <= n; i++)
        cout << team[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= t; i++)
        cout << conf[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> hate[i].F >> hate[i].S;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        wish[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> wish[i][j];
            t = max(t, wish[i][j]);
        }
    }
 
    do {
        distribute();
    } while (!check());
    print();
}
