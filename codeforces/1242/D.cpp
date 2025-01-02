#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> cache_getnormal;
unordered_map<int, int> cache_getsum;

int k;
int r;

int sumap(int l, int r) {
    return (r+l) * (r-l+1)/2;
}

int getsum(int n) {
    if (cache_getsum.count(n))
        return cache_getsum[n];
    
    if (n == 0)
        return k * (k + 1) / 2;
    
    int rem = n % k;
    int x = getsum(n / k);
    int first_val = (n / k) * r + rem * k + 1;
    int last_val = first_val + k - 1;
    
    if (x <= first_val)
        first_val += 1;
    if (x <= last_val)
        last_val += 1;
    
    int AP_sum = sumap(first_val, last_val);
    
    if (x >= first_val && x <= last_val)
        AP_sum -= x;
    
    cache_getsum[n] = AP_sum;
    return AP_sum;
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n >> k;
        
        r = k * k + 1;
        int sc = (n - 1) / r;
        int p = getsum(sc);
        
        if (p == n) {
            cout << (k + 1) * (sc + 1) << endl;
        } else {
            int tau = (p < n);
            int countbelow = (n - 1) / r * k + ((n - 1) % r - tau) / k;
            countbelow -= (n - 1) / r + tau;
            cout << n + countbelow << endl;
        }
        
        cache_getsum.clear();
        cache_getnormal.clear();
    }
    
    return 0;
}