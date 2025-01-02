#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
//#define int ll
using pii = pair<int, int>;

void Azzam() {
    int n, m;
    cin >> n >> m;
    int a[n] , b[n] , c[m];
    vector<int>ans(m);
    for(int &i : a)cin >> i;
    multiset<pii>ms;
    set<pii>s;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        s.insert({b[i] , i + 1});
        if(b[i] != a[i])
            ms.insert({b[i] , i + 1});
    }
    int last = -1;
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
        auto it = ms.lower_bound({c[i] , 0});
        if(it != ms.end() and it->first == c[i]){
            ms.erase(it);
            ans[i] = it->second;
        }else if(!ms.empty()){
            ans[i] = ms.begin()->second;
        }else{
            auto it2 = s.lower_bound({c[i] , 0});
            if(it2 != s.end() and it2->first == c[i]){
                last = it2->second;
                ans[i] = last;
            }else{
                last = 0;
                ans[i] = -1;
            }

        }
    }
    if(!last or !ms.empty()){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        if(ans[i] == -1)
            cout << last << ' ';
        else
            cout << ans[i] << ' ';
    }
    cout << '\n';

}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ;
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        Azzam();
    }
    return 0;
}