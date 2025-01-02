#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

void solution() {
    int n,c;
    cin >> n >> c;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int diff = 0 ;
    for(int i=0;i<n-1;i++){
        diff = max(diff,arr[i]-arr[i+1]);
    }
    int rasp = diff - c ;
    if(rasp > 0) cout << rasp ;
    else cout << "0";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while(t--)
    solution();
    return 0;
}