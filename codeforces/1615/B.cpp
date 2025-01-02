#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

int noOfOneBits(int n,int i){
    n++;
    int fullBaskets = n/(1LL<<(i+1));
    int ones = fullBaskets*(1LL<<i);
    int left = n%(1LL<<(i+1));
    ones += max(0LL,left-(1LL<<i));
    return ones;
}

void solve(){
    int l,r;
    cin >> l >> r;

    int ans = INT_MAX;
    for(int i=0;i<62;i++){
        int cntOne = noOfOneBits(r,i) - noOfOneBits(l-1,i);
        int cntZero = (r-l+1)-cntOne;
        ans = min(ans,cntZero);
    }
    cout << ans << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}