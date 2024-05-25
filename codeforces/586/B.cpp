#include <bits/stdc++.h>

#define int int64_t
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n-1], b[n-1];
    int c[n];
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    for(int &i : c) cin >> i;
    vector<int> r;
    for(int i=0;i<n;i++) {
        int s = c[i];
        for(int j=0;j<i;j++) {
            s+=a[j];
        }
        for(int j=i;j<n-1;j++) {
            s+=b[j];
        }
        r.push_back(s);
    }
    sort(r.begin(), r.end());
    cout << r[0] + r[1];

    return 0;
}
