#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 998244353;

template<typename T>
struct MinTree {
    static constexpr T base = {INT_MAX,-1};
    vector<T> v;
    int n, size;
    T comb(T a, T b) { //change this when doing maximum vs minimum etc.
        if(a.first < b.first) {
            return a;
        } else {
            return b;
        }
    }
    MinTree(int n = 0, T def = base) {
        this->n = n; //max number of elements
        size = 1;
        while(size < n) size *= 2;
        v.assign(size * 2, def);
    }
    void update(int pos, T val) { //update 0 indexed, assignment
        assert(pos < n && pos >= 0);
        int curr = pos + size;
        v[curr] = val;
        while(curr != 1) {
            if(curr & 1) { //non
                v[curr / 2] = comb(v[curr ^ 1], v[curr]);
            } else {
                v[curr / 2] = comb(v[curr], v[curr ^ 1]);
            }
            curr /= 2;
        }
    }
    bool isLeaf(int idx) {
        return idx >= size;
    }
    T at(int idx) {
        assert(idx >= 0 && idx < n);
        return v[idx + size];
    }
    T query(int l, int r) {//queries in range [l,r)
        return _query(1,0,size,l,r);
    }
    T _query(int idx, int currl, int currr, int &targetl, int &targetr) {
        if(currr <= targetl || currl >= targetr) return base;
        if(currl >= targetl && currr <= targetr) return v[idx];
        int mid = (currl + currr) / 2;
        return comb(
            _query(idx * 2, currl, mid, targetl, targetr),
            _query(idx * 2 + 1, mid, currr, targetl, targetr)
        );
    }
};

template<typename T>
struct MaxTree {
    static constexpr T base = {INT_MIN,-1};
    vector<T> v;
    int n, size;
    T comb(T a, T b) { //change this when doing maximum vs minimum etc.
        if(a.first > b.first) {
            return a;
        } else {
            return b;
        }
    }
    MaxTree(int n = 0, T def = base) {
        this->n = n; //max number of elements
        size = 1;
        while(size < n) size *= 2;
        v.assign(size * 2, def);
    }
    void update(int pos, T val) { //update 0 indexed, assignment
        assert(pos < n && pos >= 0);
        int curr = pos + size;
        v[curr] = val;
        while(curr != 1) {
            if(curr & 1) { //non
                v[curr / 2] = comb(v[curr ^ 1], v[curr]);
            } else {
                v[curr / 2] = comb(v[curr], v[curr ^ 1]);
            }
            curr /= 2;
        }
    }
    bool isLeaf(int idx) {
        return idx >= size;
    }
    T at(int idx) {
        assert(idx >= 0 && idx < n);
        return v[idx + size];
    }
    T query(int l, int r) {//queries in range [l,r)
        return _query(1,0,size,l,r);
    }
    T _query(int idx, int currl, int currr, int &targetl, int &targetr) {
        if(currr <= targetl || currl >= targetr) return base;
        if(currl >= targetl && currr <= targetr) return v[idx];
        int mid = (currl + currr) / 2;
        return comb(
            _query(idx * 2, currl, mid, targetl, targetr),
            _query(idx * 2 + 1, mid, currr, targetl, targetr)
        );
    }
};

void solve() {
    int n, a, b; cin >> n >> a >> b;
    a--; b--;
    vector<int> powers(n);
    MinTree<pair<int,int>> mintree(n); //used for finding ranges to the right of current antenna
    MaxTree<pair<int,int>> maxtree(n); //used for finding ranges to the left of current antenna

    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        powers[i] = num;
        if(i != a) {
            mintree.update(i,{i - num,i}); //can reach this value inclusive
            maxtree.update(i,{i + num,i}); //can reach this value inclusive
        }
    }

    queue<pair<int,int>> q;
    q.push({a,0});
    vector<int> vis(n,-1);
    while(q.size()) {
        pair<int,int> p = q.front();
        int i = p.first, step = p.second;
        q.pop();
        if(vis[i] != -1) continue;
        vis[i] = step;

        // try all antennas to the right
        while(1) {
            pair<int,int> query = mintree.query(i, i + powers[i] + 1);
            if(query.first <= i) {
                int next_idx = query.second;
                q.push({next_idx, step + 1});
                // cout << "query right " << query.first << ", " << query.second << endl;
                mintree.update(next_idx, mintree.base);
                maxtree.update(next_idx, maxtree.base);
            } else {
                break;
            }
        }

        //try all antennas to the left
        while(1) {
            pair<int,int> query = maxtree.query(i - powers[i], i + 1);
            if(query.first >= i) {
                int next_idx = query.second;
                q.push({next_idx, step + 1});
                // cout << "query left " << query.first << ", " << query.second << endl;
                mintree.update(next_idx,mintree.base);
                maxtree.update(next_idx,maxtree.base);
            } else {
                break;
            }
        }
    }
    cout << vis[b] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}