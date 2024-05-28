#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 1e6 + 5;
vector<int> q[maxn];
unordered_set<int> st[200005];

struct Node{
    int id;
    vector<int> p;

    bool operator<(const Node &t) const {
        if (p.size() != t.p.size()) return p.size() < t.p.size();
        return p < t.p;
    }

    bool operator==(const Node &t) const{
        return p == t.p;
    }
};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<Node> p;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<int> v(k);
        for(int j = 0; j < k; j++){
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        if (k != 1){
            p.push_back({i, v});
        }
        st[i] = unordered_set<int>(v.begin(), v.end());
    }
    vector<int> pos(n);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 0; i < p.size(); i++){
        auto &[id, v] = p[i]; 
        pos[id] = i;
        for(auto x : v){
            q[x].push_back(id);
        }
    }

    set<pair<int, int> > s;

    auto check = [&](int x, int y){
        if (s.contains({x, y})) return;
        s.insert({x, y});
        if (p[pos[x]].p.size() == p[pos[y]].p.size()){
            cout << "YES" << '\n';
            cout << x + 1 << ' ' << y + 1 << '\n';
            exit(0);
        }
        for(auto u : p[pos[x]].p){
            if (!st[y].contains(u)){
                cout << "YES" << '\n';
                cout << x + 1 << ' ' << y + 1 << '\n';
                exit(0);
            }
        }
    };

    for(int i = 1; i <= m; i++){
        if (q[i].empty()) continue;
        for(int j = 0; j + 1 < q[i].size(); j++){
            check(q[i][j], q[i][j + 1]);
        }
    }
    cout << "NO" << '\n';

}