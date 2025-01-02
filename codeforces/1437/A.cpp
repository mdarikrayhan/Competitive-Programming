#include <stdio.h>
#include <set>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h> 
#include <cmath>
#include <queue>
#include <stdlib.h>
#include <iostream>
#include <numeric>
using i64 = long long;
#define IOS_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"
#define PII pair<int, int>
using namespace std;
constexpr i64 inf = 1E18;
const int mod = 998244353;
void solve(){
    int l, r;
    cin >> l >> r;
    if (l >= double(r + 1) / 2){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
signed main(){
    IOS_IO
    int t;
    t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}