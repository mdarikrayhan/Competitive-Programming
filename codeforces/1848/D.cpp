#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <numeric>
#include <map> 

using namespace std;
 
#define ll long long
//const int MAXN = 16;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; cin >> t;
    while(t-->0) {
        ll s, k; cin >> s >> k;
        ll count = (5*k-s)/40;
        ll lower = 4*count - 8;
        ll upper = 4*count + 8;
        ll res = s*k;
        ll inc = 0;
        ll offset = 0;
        ll unit = s%10;
        if(s%10 == 5) {
            res = max(res, (s+5)*(k-1));
        } else if(s%10 != 0) {
            while(unit != 2) {
                inc += unit;
                unit *= 2;
                unit %= 10;
                offset++;
                res = max(res, (s+inc)*(k-offset));
            }
            //cout << inc << "\n";
            inc = max(inc, inc+(20*(count-2)));
            //cout << inc << "\n";
            unit = 2;
            for(ll i = max(0LL, lower); i < min(k,upper); i++) {
                res = max(res, (s+inc)*(k-i-offset));
                //cout << (s+inc) << " " << (k-i-offset) << "\n";
                inc += unit;
                unit = unit*2;
                unit = unit%10;
            }
        } 
        cout << res << "\n";
    }
}