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

int mod = 1e9 + 9;

ll mypow(ll n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 2;
    ll temp = mypow(n/2);
    return (temp * temp * (n%2 ? 2 : 1))%mod;
}

void solve(){
    //obviously
    //we want to not get k 
    //so greedily form groups of k - 1
    //in the case we must form a group of k - 1 more
    //we place those groups in the front to double
    ll m,n,k;
    cin >> n >> m >> k;
    ll incorrect = n - m;
    //we can disrupt at most incorrect groups
    ll groups = m/(k-1);
    groups -= m%(k-1) ? 0 : 1;
    //this is how many inc you need at least
    if(groups <= incorrect){
        cout << m%mod;
        return;
    }
    ll take = min(groups,incorrect);
    ll rem = m - take*(k-1);
    //no matter what happens this section stays togethor
    //this works cuz you'll have k * 2^n + k* 2^n/2 .... + k * 2^1
    //you'll realize that the bitwise representation
    //of this is k * 111111110
    //rem/k + 1 gives you 10000000
    //minus 1 from rem/k + 1 gives you 011111111
    //another 1 to offset the other bit
    ll res = (k * (mypow(rem/k + 1) - 2)%mod)%mod;
    res = (res + (m - (rem/k)*k) + mod)%mod;
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