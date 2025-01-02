#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
#define ll long long
using ld = long double;
#ifndef RajKariya
#define debug(x) cerr << #x << ' ' << x <<endl;
#else
#define debug(x)
#endif 
#define CASE(x)   cout << "Case #" << x << ": ";

void solution() {    
    ll n,m;
    cin >> n >> m;
//    vector<ll> a(n);
    ll mex = 1e12;
    for(int i=0;i<m;i++){
        ll l,r;
        cin >> l >> r;
        mex = min(mex, r - l + 1);
    }
    cout << mex << endl;
    for(int i=0;i<n;i++){
        cout << i % mex << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    int t = 1;
    // cin >> t;
    // cout<<fixed<<setprecision(3);
    while(t--) {
        solution();
    }

    return 0;
}