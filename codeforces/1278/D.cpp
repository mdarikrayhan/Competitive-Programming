#include <bits/stdc++.h>
 
using namespace std;
 
struct DSU{
    array<int, 500002>p;
 
    DSU (int N){
        iota(p.begin(), p.end(), 0);
    }
 
    int par(int x){
        return ((p[x] == x) ? (x) : (p[x] = par(p[x])));
    }
 
    void join(int a, int b){
        a = par(a); b = par(b);
        p[b] = a;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
 
    DSU dsu(n);
    int idx[2*n + 2], out[2*n + 2];
    for(int i = 1; i <= n; i++){    
        int l, r; cin >> l >> r;
        out[l] = r; out[r] = -1;
        idx[l] = idx[r] = i;
    }
 
    set<pair<int, int>>st;
 
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++){
        if(cnt >= n) break;
        if(out[i] != -1){
            for(auto &[r, id]: st){
                if(r > out[i]) break;
                dsu.join(idx[i], id);
                cnt++;
 
                if(cnt > n) break;
            }
            st.insert({out[i], idx[i]});
        } else{
            st.erase({i, idx[i]});
        }
    }
 
    bool ok = (cnt == n - 1);
    for(int i = 2; i <= n; i++){
        ok &= (dsu.par(1) == dsu.par(i));
    }
 
    if(ok) cout << "YES\n";
    else cout << "NO\n";
 
    return 0;
}