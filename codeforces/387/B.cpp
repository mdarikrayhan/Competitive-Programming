#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long 
#define ld long double 
#define M 1000000007
#define endl '\n' 
using namespace std; 

void solve() {
    int n, m; cin >> n >> m;
    int arr[n], brr[m];

    for(int count = 0; count < n; count++) cin >> arr[count];
    for(int bount = 0; bount < m; bount++) cin >> brr[bount];

    sort(arr, arr + n);
    sort(brr, brr + m);

    int eenie = n - 1 , menie = m - 1;

    int rount = 0;
    while(eenie >= 0 && menie >= 0) {
        if(arr[eenie] <= brr[menie]) {
            eenie--;
            menie--;
        } else {
            rount++;
            eenie--;
        }
    }
    cout << rount + eenie + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int _t; cin >> _t; while(_t--) 
        solve();
    return 0;
}