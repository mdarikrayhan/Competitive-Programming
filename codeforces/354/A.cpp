#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#define ll long long
using namespace std;

ll get(vector<ll>& pre,int l,int r){
    if(l > r)
        return 0;
    return pre[r] - (l ? pre[l-1] : 0);
}

void solve(){
    //2 ends
    //one op will cost w*l/r
    //if same hand the + q l/r
    //observation 1
    //alternating hands is always cheaper than using 1 hand contin
    //2
    //there's gonna be some middle element such that
    //it can be picked up with either L or R
    //all elements to L/R must be picked up with l/r
    //we're also going to have min(l,r) swaps
    //since q l/r is constant
    //just sum up the l and r
    //and add how many swaps cannot be forced
    //the middle element should be picked up by the cheaper hand
    ll n,l,r,ql,qr;
    cin >> n >> l >> r >> ql >> qr;
    vector<ll> pre(n);
    for(int i = 0;i<n;i++){
        cin >> pre[i];
        pre[i] += i ? pre[i-1] : 0;
    }

    ll res = get(pre,0,n-1) * r + (n - 1)*qr;

    for(int i = 0;i<n;i++){
        ll lp = get(pre,0,i) * l;
        ll rp = get(pre,i+1,n-1) * r;
        //this will be the last element
        //just consider this element to be the last on the left edge
        ll rs = n - 1 - i;
        ll ls = i + 1;
        ll val = lp + rp;
        if(ls < rs){
            res = min(res,val + max((ll)0,(rs - ls - 1)) * qr);
        }
        else{
            res = min(res,val + max((ll)0,(ls - rs - 1)) * ql);
        }
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--){
    solve();
    //}
    return 0;
}

void print(vector<vector<int>>& a){
    for(auto& b : a){
        for(auto& i : b){
            cout << i << " ";
        }
        cout << "\n";
    }
}