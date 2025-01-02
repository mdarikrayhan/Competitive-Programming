#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(a) (a).rbegin(), (a).rend()

const ll mod = 1e9+7;
const int N = 1e5+100;
const int inf = (1ll<<30)-1;


void slv(){
    int n; cin >> n;
    vector<pair<int, int>> ps, ng;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x>0) ps.eb(x, i);
        else ng.eb(x, i);
    }
    vector<int> ans(n);
    if(n == 3 && ps.size() == 1 && ng.size() == 2){
        auto [a, i1] = ps.back(); ps.pop_back();
        auto [b, i2] = ng.back(); ng.pop_back();
        auto [c, i3] = ng.back(); ng.pop_back();
        ans[i1] = b+c;
        ans[i2] = -a;
        ans[i3] = -a;
    }
    if(n == 3 && ps.size() == 2 && ng.size() == 1){
        auto [a, i1] = ng.back(); ng.pop_back();
        auto [b, i2] = ps.back(); ps.pop_back();
        auto [c, i3] = ps.back(); ps.pop_back();
        ans[i1] = b+c;
        ans[i2] = -a;
        ans[i3] = -a;
    }
    if(ps.size() == 1){
        auto [a, i1] = ps.back();
        auto [b, i2] = ng.back();
        ps.pop_back();
        ng.pop_back();
        ans[i1] = b;
        ans[i2] = -a;
    }
    if(ng.size() == 1){
        auto [a, i1] = ng.back();
        auto [b, i2] = ps.back();
        ng.pop_back();
        ps.pop_back();
        ans[i1] = -b;
        ans[i2] = a;
    }
    if(ps.size()&1){
        auto [a, i1] = ps.back(); ps.pop_back();
        auto [b, i2] = ps.back(); ps.pop_back();
        auto [c, i3] = ps.back(); ps.pop_back();
        ans[i1] = -(b+c);
        ans[i2] = a;
        ans[i3] = a;
    }
    if(ng.size()&1){
        auto [a, i1] = ng.back(); ng.pop_back();
        auto [b, i2] = ng.back(); ng.pop_back();
        auto [c, i3] = ng.back(); ng.pop_back();
        ans[i1] = b+c;
        ans[i2] = -a;
        ans[i3] = -a;
    }
    while(!ps.empty()){
        auto [a, i1] = ps.back(); ps.pop_back();
        auto [b, i2] = ps.back(); ps.pop_back();
        ans[i1] = -b;
        ans[i2] = a;
    }
    while(!ng.empty()){
        auto [a, i1] = ng.back(); ng.pop_back();
        auto [b, i2] = ng.back(); ng.pop_back();
        ans[i1] = b;
        ans[i2] = -a;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}



int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        slv();
    }
    return 0;
}