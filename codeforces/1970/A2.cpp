#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101, M = 1e9, mod = 998244353;
#define sz(x) int(x.size())
void solve();
void init() {}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(0) << fixed;
    init();
    int t = 1;
    while (t--) solve();
}

void solve(){
    string s; cin >> s;
    int c = 0,n=sz(s),idx=-1,cur=0,now=1;
    vector<vector<int>>G(n+1);
    for(int i = 0; i < n; i++){
        if(s[i] == ')') {idx=i;break;}
        c++;
        G[0].push_back(1);
    }
    for(int i = idx; i < n; i++){
        if(s[i] == ')') c--;
        else cur++;

        if(c < 0){
            c = cur-1;
            cur = 0;
            now++;
        }
        if(s[i] == ')') G[now].push_back(-1);
        else G[now].push_back(1);
    }

    for(int i = 0; i <= n; i++) reverse(G[i].begin(), G[i].end());
    
    c = 0;
    vector<int>ptr(n+1);
    while(true){
        if(ptr[c] == G[c].size()) break;
        int v = G[c][ptr[c]];
        if(v == 1) cout << '(';
        else cout << ')';
        ptr[c]++;
        c += v;
    }
}
