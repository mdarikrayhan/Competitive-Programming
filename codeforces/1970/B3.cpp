#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
auto &operator<<(auto &o, pair<auto, auto> p) {
    return o << "()" << p.first << ", " << p.second <<")";
}
auto operator<<(auto &o, auto x)-> decltype(x.end(), o) {
    o << "{";int i = 0;
    for(auto e : x) o << ", "+!i++<<e;
    return o <<"}";
}
#define debug(x...) cerr << "["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<endl;}(x)
#else
#define debug(...) {}
#endif
 
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second
typedef pair <int, int> pii;
 
void test() {
    int n; cin>>n;
    vector <pii> v(n);
    for (int i=0; i<n; ++i) {
        cin>>v[i].fi;
        v[i].se = i;
    }
    sort(all(v));
    vector <pii> res(n);
    vector <int> res2(n);
    vector<int> res3(n);
    vector<int> res4(n);
    bool ok = (v[0].fi == 0);
    if (!ok) {
        for (int i=1; i<n; ++i) {
            if (v[i].fi == v[i-1].fi) {
                swap(v[0], v[i-1]);
                sort(v.begin()+1, v.end());
                ok = true;
                break;
            }
        }
    }
    debug("xd");
    if (ok) {
        debug(v);
        res[v[0].se] = {1, 1};
        res2[0] = 1;
        res3[0] = v[0].se;
        res4[v[0].se] = (v[0].fi ? 0 : v[0].se);
        for (int i=1; i<n; ++i) {
            if (v[i].fi == 0) {
                res[v[i].se] = {i+1, 1};
                res2[i] = 1;
                res3[i] = v[i].se;
                res4[v[i].se] = v[i].se;
                continue;
            }
            
            if (v[i].fi == v[0].fi && res4[v[0].se] == 0) {
                res4[v[0].se] = v[i].se;
            }
            if (v[i].fi <= i) {
                res[v[i].se] = {i+1, res2[i-v[i].fi]};
                res2[i] = res2[i-v[i].fi];
                res3[i] = v[i].se;
                res4[v[i].se] = res3[i-v[i].fi];
            }
            else {
                res[v[i].se] = {i+1, 1 + v[i].fi - i};
                res2[i] = 1 + v[i].fi - i;
                res3[i] = v[i].se;
                res4[v[i].se] = res3[0];
            }
        }
    }
    else {
        if (n == 2) {
            cout<<"NO\n";
            return;
        }
        res3[0] = v[2].se;
        res3[1] = v[1].se;
        res3[2] = v[0].se;
        for (int i=0; i<n; ++i) {
            if (v[i].fi > 3) {
                res[v[i].se] = {v[i].fi, 2};
                res4[v[i].se] = res3[0];
            }
            else if (v[i].fi == 3) {
                res[v[i].se] = {1, 1};
                res4[v[i].se] = res3[2];
            }
            else if (v[i].fi == 2) {
                res[v[i].se] = {4 - v[i].fi, 2};
                res4[v[i].se] = res3[0];
            }
            else {
                res[v[i].se] = {4 - v[i].fi, 2};
                res4[v[i].se] = res3[1];
            }
        }
    }
    cout<<"YES\n";
    for (auto &[x, y] : res) {
        cout<<x<<' '<<y<<'\n';
    }
    for (int x : res4) {
        cout<<x+1<<' ';
    }
    cout<<'\n';
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1; 
  while (t--) {
    test();
  }
}