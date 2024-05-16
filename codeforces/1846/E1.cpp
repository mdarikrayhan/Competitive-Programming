#include<bits/stdc++.h>
using namespace std;

using LL = long long;

set<long long> nums;

void solve() {
    long long n;
    cin >> n;

    if (nums.count(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    for (long long k = 2; k <= 1000; ++k) { 
        // initialize val = 1 + k to ensure that there must be at least 2 layers
        long long val = 1 + k;
        // initialize p = k^2
        long long p = k*k;
        for (int cnt = 2; cnt <= 20; ++cnt) { // 20 is enough

            val += p; // add the current layer

            if (val > 1e6) break;// if val > 1e6, then the next val will be larger than 1e6
            // if val <= 1e6, then insert val into the set
            nums.insert(val);            
            p *= k; // update p
        }
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}