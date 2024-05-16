#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n-1; i >= 0; i--)
#define all(s) (s).begin() , (s).end()
#define rall(s) (s).rbegin() , (s).rend()

void solve(int nigga) {
    // Your code goes here
    int x ; cin >> x ;
    vector<int>a;
    a.push_back(x);
    while(__builtin_popcount(x) > 1){
        int p = __builtin_ctz(x);
        x -= (1<<p);
        a.push_back(x);
    }
    while(x > 1){
        x/=2 ;
        a.push_back(x);
    }
    cout << a.size() << endl;
    for(int i = 0 ; i < a.size() ; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE 

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    #endif

    int t;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}