#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(__null);
using namespace std;

void sol()
{
    int n;
    cin >> n;
    
    vector<int> v1(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    
    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << -n * v1[i] << " ";
    }
    cout << endl;
    
    cout << n << " " << n << endl;
    cout << (n - 1) * v1[n - 1] << endl;
    
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        return;
    }
    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << (n - 1) * v1[i] << " ";
    }
    cout << endl;
    
}

signed main()
{
    fastio()
    
        int k;
    k = 1;
    // cin >> k;
    while (k--)
        sol();
    return 0;
}