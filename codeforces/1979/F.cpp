#include <bits/stdc++.h>
using namespace std;
 
pair <int, int> ask(int d) {
    cout << "? " << d << endl;
    int v, u;
    cin >> v >> u;
    return {v, u};
}
 
pair <int, int> get(int n, vector <int>& nxt) {
    if (n == 1) {
        int v = ask(0).first;
        return {v, v};
    }
    if (n == 2) {
        int u = ask(0).first;
        int v = ask(0).first;
        nxt[u] = v;
        return {u, v};
    }
    pair <int, int> t = ask(n - 2);
    int v = t.first;
    int ban = t.second;
    if (ban != 0) {
        pair <int, int> res = get(n - 1, nxt);
        if (ban != res.first) {
            nxt[v] = res.first;
            return {v, res.second};
        } else {
            nxt[res.second] = v;
            return {res.first, v};
        }
    } else {
        int u = ask(0).first;
        nxt[u] = v;
        pair <int, int> res = get(n - 2, nxt);
        nxt[v] = res.first;
        return {u, res.second};
    }
}
 
void solve() {
    int n;
    cin >> n;
    
    vector <int> nxt(n + 1, -1);
    pair <int, int> ans = get(n, nxt);
    
    int v = ans.first;
    cout << "! ";
    do {
        cout << v << " ";
        v = nxt[v];
    } while (v != -1);
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}