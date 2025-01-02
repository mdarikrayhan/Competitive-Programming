#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector <int> a(k);
    ll s = 0, cnt = 0, cnt2 = 0;

    for(auto &i: a) {
        cin >> i;
        s += i;
        cnt += (i < y);
        cnt2 += (i >= y);
    }

    if(cnt > (n - 1) / 2 || s > x) {
        cout << "-1\n";
        return 0;
    }

    vector <int> List;
    while(cnt2 < (n + 1) / 2) {
        List.push_back(y);   
        s += y;
        ++cnt2;
    }

    while(cnt2 + cnt < n) {
        List.push_back(1);
        ++s;
        ++cnt2;
    } 

    if(s > x) {
        cout << "-1\n";
    } else {
        for(auto &i: List) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
