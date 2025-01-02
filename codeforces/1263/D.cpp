#include<bits/stdc++.h>
#define jettdash ios_base::sync_with_stdio(0),cin.tie(0) ,cout.tie(0)
#define ll long long
#define yn(flag) cout<<((flag) ? "YES\n":"NO\n");
#define endl "\n"
#define clr(dp) memset(dp,-1,sizeof dp)
#define all(a) a.begin(),a.end()
#define getmax(v) *max_element(all(v))
#define getmin(v) *min_element(all(v))
#define sum(v) accumulate(all(v),0ll)
int MOD=1e9+7;
using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};


int main() {
    jettdash;
    int n;
    cin >> n;
    vector<string> v(n);
    union_find dsu(n + 5);
    vector<int> frq(26);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (auto x: v[i]) {
            if (frq[x - 'a'])dsu.unite(i + 1, frq[x - 'a']);
            else frq[x - 'a'] = i + 1;
        }
    }
    set<int> groups;
    for (int i = 1; i <= n; i++)groups.insert(dsu.find(i));
    cout << groups.size() << endl;
}