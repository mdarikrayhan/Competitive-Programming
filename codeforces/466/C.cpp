#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif
#define int long long
#define double long double
#define endl "\n"
#define all(x) x.begin(), x.end()
#define __builtin_popcount __builtin_popcountll
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key


void solve(){
    int n; cin >> n;
    vector<int>a(n);
    for(int &i : a) cin >> i;
    int index1 = -1, index2 = -1;
    int fsum = 0;
    int sum = accumulate(all(a), 0LL);
    if(sum % 3 != 0){
        cout << 0 << endl; return;
    }
    for(int i = 0; i < n; i++){
        fsum += a[i];
        if(fsum == sum / 3){
            index1 = i;
            break;
        }
    }
    if(index1 == -1){
        cout << 0 << endl; return;
    }
    fsum = 0;
    for(int i = n - 1; i > index1; i--){
        fsum += a[i];
        if(fsum == sum / 3){
            index2 = i;
            break;
        }
    }
    if(index2 == -1){
        cout << 0 << endl; return;
    }
    debug(sum);
    if(sum == 0){
        fsum = 0;
        int num = 0;
        for(int i = 0; i < n; i++){
            fsum += a[i];
            num += !fsum;
        }
        cout << ((num - 1) * (num - 2))/2LL << endl;
    }
    else{
        fsum = 0;
        int cntb = 1;
        int lim = 0;
        vector<int>back(n, 0);
        for(int i = index2 - 1; i > index1; i--){
            fsum += a[i];
            cntb += !fsum;
            back[i] = cntb;
        }
        int ans = back[index1 + 1];
        fsum = 0;
        for(int i = index1 + 1; i < index2; i++){
            fsum += a[i];
            ans += (fsum == 0) * back[i + 1];
        }
        cout << ans << endl;
    }
}   

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}