#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
using ll = long long;
const int maxn = 2e5 + 7;
const int INF = 1e18 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool flag = 0;
        flag |= (b == d && a + c == d);
        flag |= (b == c && a + d == c);
        flag |= (a == d && b + c == d);
        flag |= (a == c && b + d == c);
        if (flag) yes;
        else no;
    }
    
    return 0;
}